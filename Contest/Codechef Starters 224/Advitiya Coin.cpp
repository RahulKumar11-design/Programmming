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

int dp[N][2][2];

int rec(vector<int>& p,int k,int i,int j,bool type,bool trans_end){
    if(j==p.size()){
        return 0;
    }
    if(dp[j][type][trans_end]!=-1){
        return dp[j][type][trans_end];
    }
    int wins=0;
    if(!trans_end){
        //buy first
        int buy = rec(p,k,j,j+1,1,1);

        int sell = rec(p,k,j,j+1,0,1);

        int skip = rec(p,k,i,j+1,0,0);

        wins = max(buy,sell);
        wins = max(wins,skip);
    }else{
        int buy=0,sell=0;
        if(type==0){
            if(p[i]-p[j]-k>0)
                buy = 1+rec(p,k,j,j+1,0,0);
        }else{
            if(p[j]-p[i]-k>0)
                sell = 1+rec(p,k,j,j+1,0,0);
        }
        wins = max(buy,sell);

        int skip = rec(p,k,i,j+1,type,1);

        wins = max(wins,skip);
    }

    return dp[j][type][trans_end] = wins;
}

void solve() {
    // Your code here
    int n,k;
    cin >> n >> k;
    vector<int> p(n);

    for(int i=0;i<n;i++) cin >> p[i];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j][0]=dp[i][j][1]=-1;
        }
    }

    cout << rec(p,k,0,0,0,0) << endl;
}

int32_t main() {
    fast_io();

    // single test case:
    // solve();

    // multiple test cases:
    int t; cin >> t; while(t--) solve();

    return 0;
}