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

void solve() {
    // Your code here
    ll a,b;
    cin >> a >> b;

    int tza=64,tzb=64;
    for(int i=0;i<64;i++){
        if((a&(1ll<<i))){
            tza=i;
            break;
        }
    }
    for(int i=0;i<64;i++){
        if((b&(1ll<<i))){
            tzb=i;
            break;
        }
    }
    a>>=tza;b>>=tzb;

    if(a!=b){
        cout << "-1\n";
    }else{
        int diff = abs(tza-tzb);
        cout << diff/3 + (diff%3)/2 + (diff%3)%2 << "\n";
    }
}

int32_t main() {
    fast_io();

    // single test case:
    // solve();

    // multiple test cases:
    int t; cin >> t; while(t--) solve();

    return 0;
}