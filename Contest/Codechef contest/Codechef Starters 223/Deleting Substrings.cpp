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
const int N = 1e5 + 1;

int dp[200005][105][2];

int rec(string &s,string &t,int i,int j,bool prev_taken){
    if(i==s.length()){
        if(j==t.length()){
            return 0;
        }else{
            return -1;//invalid
        }
    }else if (j == t.length()) {
        // delete remaining S in one operation
        return 1;
    }


    if(dp[i][j][prev_taken]!=INT_MAX){
        return dp[i][j][prev_taken];
    }
    int take = -1;

    if(s[i]==t[j]){
        take = rec(s,t,i+1,j+1,true); 
    }

    int not_take = rec(s,t,i+1,j,false);

    if(not_take!=-1){
        not_take+=(prev_taken?1:0);
        if(take!=-1){
            return dp[i][j][prev_taken] = min(take,not_take);
        }else{
            return dp[i][j][prev_taken] = not_take;
        }
    }else if(take!=-1){
        return dp[i][j][prev_taken] = take;
    }else{
        return dp[i][j][prev_taken] = -1;
    }
}

void solve() {
    // Your code here
    int n,m;
    cin >> n >> m;
    string s,t;
    cin >> s >> t;

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j][0]=INT_MAX;
            dp[i][j][1]=INT_MAX;
        }
    }

    cout << rec(s,t,0,0,true) << "\n";

}

int32_t main() {
    fast_io();

    // single test case:
    // solve();

    // multiple test cases:
    int t; cin >> t; while(t--) solve();

    return 0;
}