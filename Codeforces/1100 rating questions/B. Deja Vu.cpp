#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

// loop macros
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i <= (n); i++)
#define repr(i, n) for (int i = (n)-1; i >= 0; i--)
#define repab(i, a, b) for (int i = (a); i <= (b); i++)
#define repba(i, b, a) for (int i = (b); i >= (a); i--)

// container & utility macros
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ff first
#define ss second

// type shortcuts
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int,int>
#define pll pair<long long,long long>
#define vpi vector<pair<int,int>>

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

#ifdef LOCAL
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

const int MOD = 1e9 + 7;
const ll INF = 1e18;
const int N = 2e5 + 5;

void solve() {
    int n,q;
    cin >> n >> q;
    vll a(n);
    rep(i,n) cin >> a[i];

    map<int,long long> mp;
    
    int prev;cin >> prev;
    mp[prev]=pow(2,prev-1);

    for(int i=1;i<q;i++){
        int xi;cin >> xi;
        if(prev>xi){
            mp[xi]=pow(2,xi-1);
            prev = xi;
        }
    }
    ll csum = 0;
    for(auto [xi,val]:mp){
        mp[xi]+=csum;
        csum+=val;
    }

    for(int i=0;i<n;i++){
        int tz = __builtin_ctz(a[i]);

        auto it = mp.upper_bound(tz);

        if(it!=mp.begin()){
            it--;
            a[i] += it->second;
        }
    }

    rep(i,n) cout << a[i] << " ";

    cout << endl;
}

int32_t main() {
    fast_io();

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}