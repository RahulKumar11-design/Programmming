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
    int n;
    cin >> n;

    vi a(n);
    for(int i=0;i<n;++i) cin >> a[i];
    vi b(n);
    for(int i=0;i<n;++i) cin >> b[i];

    ll greed_gift = 0;

    for(int i=n-1;i>=0;i--){
        ll d = b[i]-(a[i]+greed_gift);
        if(d<0){
            greed_gift = -d;
        }else{
            greed_gift = 0;
        }
    }

    if(greed_gift!=0){
        no;
    }else{
        yes;
    }
}

int32_t main() {
    fast_io();

    //solve();

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}