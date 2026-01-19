#include <iostream>
#include <vector>
#include <set>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> coins(n);
    int totsum = 0;
    for(int i=0;i<n;i++){
        cin >> coins[i];
        totsum+=coins[i];
    }

    vector<vector<bool>> dp(n+1,vector<bool>(totsum+1,false));
    //initialise
    for(int i=0;i<=n;i++)
        dp[i][0] = true;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=totsum;j++){
            //exclude
            dp[i][j] = dp[i-1][j];
            //include
            if(coins[i-1]<=j){
                dp[i][j] = dp[i][j] || dp[i-1][j-coins[i-1]]; 
            }
        }
    }

    vector<int> comb;

    for(int j=1;j<=totsum;j++){
        if(dp[n][j]){
            comb.push_back(j);
        }
    }

    cout << comb.size() << "\n";
    for(int coin_sum:comb){
        cout << coin_sum << " ";
    }
}

int main() {
    solve();
}