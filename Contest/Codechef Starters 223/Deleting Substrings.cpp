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
    int N,M;
    cin >> N >> M;
    string S,T;
    cin >> S >> T;

    const int INF = 1e9;
    vector<vector<int>> dp(N+1, vector<int>(M+1, INF));

    dp[0][0] = 0;
    for(int i=1;i<=N;i++)
        dp[i][0] = 1;

    for(int i=1;i<=N;i++){
        for(int j=0;j<=M;j++){
            dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);

            if(j>0 && S[i-1]==T[j-1]){
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            }
        }
    }

    int ans = dp[N][M];
    if(ans >= INF) cout << -1 << "\n";
    else cout << ans << "\n";
    
}

int32_t main() {
    fast_io();

    // single test case:
    // solve();

    // multiple test cases:
    int t; cin >> t; while(t--) solve();

    return 0;
}