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
    int a,b;
    cin >> a >> b;

    if(a==b){
        cout << "infinity\n";
        return;
    }

    int ct = 0;
    int n = a-b;

    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            if(i>b){
                ct++;
            }

            if(i*i!=n && n/i>b){
                ct++;
            }
        }
    }

    cout << ct << "\n";
}

int32_t main() {
    fast_io();

    // single test case:
    solve();

    // multiple test cases:
    // int t; cin >> t; while(t--) solve();

    return 0;
}