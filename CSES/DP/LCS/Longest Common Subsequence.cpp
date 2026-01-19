#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int max(int a,int b){
    if(a>b) return a;
    else return b;
}

vector<vector<int>> lcs(vector<int> a,vector<int> b){
    int n=a.size(),m=b.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    return dp;
}

void solve() {
    int n,m;
    cin >> n >> m;
    vector<int> a(n),b(m);

    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    for(int i=0;i<m;i++){
        cin >> b[i];
    }

    vector<vector<int>> dp = lcs(a,b);

    int i=n,j=m;
    stack<int> st;

    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            st.push(a[i-1]);
            i--;j--;
        }else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }else{
            j--;
        }
    }

    vector<int> v;
    while(!st.empty()){
        v.push_back(st.top());
        st.pop();
    }

    cout << v.size() << "\n";

    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
}

int main() {
    solve();
    return 0;
}