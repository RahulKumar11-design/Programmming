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
    int n,k;
    cin >> n >> k;
    vector<int> p(n);

    for(int i=0;i<n;i++) cin >> p[i];

    if(n==1){
        cout << "0\n";
        return;
    }

    int mini=p[0],maxi=p[0],wins=0;

    for(int i=1;i<n;i++){
        mini = min(mini,p[i]);
        maxi = max(maxi,p[i]);

        if(maxi-mini>k){
            wins++;
            if(i+1<n){
                mini = p[i+1];
                maxi = p[i+1];
            }
        }
    }

    cout << wins << "\n";
}

int32_t main() {
    fast_io();

    // single test case:
    // solve();

    // multiple test cases:
    int t; cin >> t; while(t--) solve();

    return 0;
}