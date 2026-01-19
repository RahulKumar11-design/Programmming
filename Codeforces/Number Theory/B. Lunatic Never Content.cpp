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
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    int j;
    for(j=0;j<n/2;j++){
        if(a[j]!=a[n-j-1]){
            break;
        }
    }
    if(j==n/2){
        cout << "0\n";
        return;
    }

    int gcd = 0;
    for(int i=0;i<n/2;i++){
        int mod = abs(a[i]-a[n-i-1]);

        gcd = __gcd(gcd,mod);
    }

    cout << gcd << "\n";
}

int32_t main() {
    fast_io();

    // single test case:
    // solve();

    // multiple test cases:
    int t; cin >> t; while(t--) solve();

    return 0;
}