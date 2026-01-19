#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

const int mod = 1e9+7;
long long mod_inverse_2 = 500000004;


void solve() {
    // Your code here
    int n;
    cin >> n;
    int tot_sum = (n*(n+1))/2;

    if(tot_sum%2!=0){
        cout << 0;
        return;
    }

    int sum = tot_sum/2;

    vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
    for(int i=0;i<=n;i++){
        dp[i][0] = 1;
    }

    for(int i=1;i<=n;i++){
        int wt = i;
        for(int j=1;j<=sum;j++){
            int exc = dp[i-1][j];
            int inc = 0;
            if(wt<=j){
                inc = dp[i-1][j-wt];
            }
            dp[i][j] = (inc+exc)%mod;
        }
    }
    //all set == totsum/2 
    //pair = tot_set/2
    cout << (dp[n][sum]*mod_inverse_2)%mod;
}

int32_t main() {
    fast_io();
    solve();

    return 0;
}