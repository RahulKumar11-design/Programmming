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

void solve() {
    int n,m;
    cin >> n >> m;

    vi odd,even;
    for(int i=1;i<=n;++i){
        int ai;cin >> ai;
        if(i%2==0){
            even.push_back(ai);
        }else{
            odd.push_back(ai);
        }
    }

    sort(rall(even));
    sort(rall(odd));

    int l=0,r=0;

    for(int i=0;i<m;i++){
        int mi;cin >> mi;

        if(mi%2!=0){
            if(l==odd.size() || (l>0 && odd[l]<0)){
                continue;
            }else{
                l++;
            }
        }else{
            if(r==even.size() || (r>0 && even[r]<0)){
                continue;
            }else{
                r++;
            }
        }
    }

    ll sum = 0;

    for(;l<odd.size();l++){
        sum+=odd[l];
    }
    for(;r<even.size();r++){
        sum+=even[r];
    }

    cout << sum << endl;
}

int32_t main() {
    fast_io();

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}