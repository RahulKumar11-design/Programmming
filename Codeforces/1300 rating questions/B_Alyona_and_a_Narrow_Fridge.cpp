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

bool fn(vpi& a,int k,int h){
    bool n_sp = true;
    for(auto &[val,idx]:a){
        if(idx<=k){
            if(n_sp){
                h-=val;
                n_sp=false;
            }else{
                n_sp=true;
            }
        }

        if(h<0){
            return false;
        }
    }

    return true;
}

void solve() {
    int n,h;
    cin >> n >> h;

    vpi a(n);
    for(int i=0;i<n;++i){
        cin >> a[i].ff;
        a[i].ss=i+1;
    }
    sort(rall(a));

    int low=1,high=n,ans=1;

    while(low<=high){
        int mid = low+(high-low)/2;

        if(fn(a,mid,h)){
            low = mid+1;
            ans = mid;
        }else{
            high = mid-1;
        }
    }

    cout << ans << endl;
}

int32_t main() {
    fast_io();

    // int t;
    // cin >> t;
    // while (t--) solve();

    solve();

    return 0;
}