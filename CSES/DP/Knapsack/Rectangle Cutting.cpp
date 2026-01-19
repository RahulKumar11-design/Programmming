#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int m,n;
    cin >> m >> n;

    vector<vector<int>> dp(m+1,vector<int>(n+1));

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = INT_MAX;
            //vertical cut
            for(int k=1;k<j;k++){
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[i][j-k]+1);
            }
            //horizontal cut
            for(int k=1;k<i;k++){
                dp[i][j] = min(dp[i][j],dp[k][j]+dp[i-k][j]+1);
            }
        }
    }

    cout << dp[m][n];
}

int32_t main() {
    fast_io();

    solve();

    return 0;
}