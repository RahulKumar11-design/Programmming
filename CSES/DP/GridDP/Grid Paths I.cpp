#include <iostream>
#include <vector>
using namespace std;

const int mod = (int)1e9+7;

void solve() {
    int n;
    cin >> n;
    vector<vector<char>> grid(n,vector<char>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> grid[i][j];
        }
    }

    vector<vector<long>> dp(n,vector<long>(n,0));
    //base case
    for(int i=0;i<n;i++){
        if(grid[i][0]=='*') break;
        dp[i][0] = 1;
    }
    for(int i=0;i<n;i++){
        if(grid[0][i]=='*') break;
        dp[0][i] = 1;
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(grid[i][j]=='.'){
                dp[i][j] = (dp[i-1][j]+dp[i][j-1])%mod;
            }
        }
    }

    cout << dp[n-1][n-1];
}

int main() {
    solve();
    return 0;
}