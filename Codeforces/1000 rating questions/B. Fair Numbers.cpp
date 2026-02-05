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

const int MOD = 1e9 + 7;
const ll INF = 1e18;
const int N = 2e5 + 5;

bool check(ll x){
    ll temp = x;

    while(x>0){
        int dig = x%10;

        if(dig!=0 && temp%dig!=0){
            return false;
        }

        x/=10;
    }

    return true;
}

void solve() {
    // Your code here
    ll n;
    cin >> n;

    while(true){
        if(check(n)){
            break;
        }
        n++;
    }

    cout << n << "\n";
}

int32_t main() {
    fast_io();

    // single test case:
    // solve();

    // multiple test cases:
    int t; cin >> t; while(t--) solve();

    return 0;
}