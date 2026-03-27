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
    int n,k;
    cin >> n >> k;

    vector<int> bits(31,n);
    for(int i=0;i<n;++i){
        int ai;cin >> ai;

        for(int i=30;i>=0;i--){
            if(ai&(1<<i)){
                bits[i]--;
            }
        }
    }

    for(int i=30;i>=0;i--){
        if(k-bits[i]>=0){
            k-=bits[i];
            bits[i]=0;
        }
    }

    ll ans = 0,p=1;

    for(int i=0;i<31;i++){
        if(bits[i]==0){
            ans+=p;
        }
        p*=2;
    }

    cout << ans << endl;
}

int32_t main() {
    fast_io();

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}