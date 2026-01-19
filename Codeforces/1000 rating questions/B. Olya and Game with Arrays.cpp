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
const int INF = 1e18;
const int N = 2e5 + 5;

void solve() {
    // Your code here
    int n;
    cin >> n;
    vector<vector<int>> arr(n);

    for(int i=0;i<n;i++){
        int m;
        cin >> m;
        arr[i].resize(m);
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }

    for(int i=0;i<n;i++){
        sort(arr[i].begin(),arr[i].end());
    }

    ll sum = 0;
    int mini=arr[0][0],mini1 = arr[0][1];

    for(int i=0;i<n;i++){
        sum+=arr[i][1];
        mini = min(mini,arr[i][0]);
        mini1 = min(mini1,arr[i][1]);
    }

    sum = sum - mini1 + mini;

    cout << sum << endl;
}

int32_t main() {
    fast_io();

    // single test case:
    // solve();

    // multiple test cases:
    int t; cin >> t; while(t--) solve();

    return 0;
}