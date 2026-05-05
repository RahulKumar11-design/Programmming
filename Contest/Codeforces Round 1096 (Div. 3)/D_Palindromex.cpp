#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

// container & utility macros
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second

// type shortcuts
using ll  = long long;
using vi  = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vpi = vector<pii>;

// algorithm helpers
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

// output shortcuts
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

const int MOD = 1e9 + 7;
const ll INF = 1e18;
const int N = 2e5 + 5;

int calc_mex(set<int>& st){
    int i;
    
    for(i=1;i<=st.size();i++){
        if(!st.count(i)){
            break;
        }
    }

    return i;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(2*n),zero;
    for(int i=0;i<2*n;++i){
        int ai;cin >> ai;
        a[i] = ai;
        if(ai==0){
            zero.push_back(i);
        }
    }
    int maxi_mex = 1;

    for(int pos=0;pos<=1;pos++){
        set<int> st;
        int l,r;
        l = zero[pos]-1;
        r = zero[pos]+1;

        while(l>=0 && r<2*n){// O(nlogn)
            if(a[l]!=a[r]){
                break;
            }else{
                st.insert(a[l]);
                l--;r++;
            }
        }

        int mex = calc_mex(st);//O(nlogn)

        maxi_mex = max(maxi_mex,mex);
    } 

    //inbound

    int l=zero[0]+1,r=zero[1]-1;
    set<int> st;

    while(l<=r){
        if(a[l]!=a[r]){
            break;
        }else{
            st.insert(a[l]);
            l++;r--;
        }
    }

    if(l<r){
        cout << maxi_mex << endl;
    }else{
        l=zero[0]-1;r=zero[1]+1;

        while(l>=0 && r<2*n){
            if(a[l]!=a[r]){
                break;
            }else{
                st.insert(a[l]);
                l--;r++;
            }
        }

        int mex = calc_mex(st);

        maxi_mex = max(maxi_mex,mex);

        cout << maxi_mex << endl;
    }
}

int32_t main() {
    fast_io();

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}