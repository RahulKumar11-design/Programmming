#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

#ifdef LOCAL
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const ll N = 2e5 + 5;

void solve() {
    // Your code here
    ll a,b,c;
    cin >> a >> b >> c;

    ll b_c=1;

    while(c){
        if(c&1){
            b_c=(b_c*b)%(MOD-1);
        }
        b=(b*b)%(MOD-1);
        c>>=1;
    }

    ll a_b_c = 1;

    while(b_c){
        if(b_c&1){
            a_b_c=(a_b_c*a)%MOD;
        }
        a = (a*a)%MOD;
        b_c>>=1;
    }

    cout << a_b_c << endl;
}

int32_t main() {
    fast_io();

    // single test case:
    // solve();

    // multiple test cases:
    int t; cin >> t; while(t--) solve();

    return 0;
}