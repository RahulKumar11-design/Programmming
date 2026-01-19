#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

long long min(long long a,long long b){
    if(a<b) return a;
    else return b;
}

long long sum_short_dist(vector<vector<long long>> &d,int u,int v,int c){
    long long sum=0;
    d[u][v] = min(d[u][v],c);
    d[v][u] = min(d[v][u],c);

    //i --- u-v --- j => if short then update
    for(int i=0;i<d.size();i++){
        for(int j=0;j<d.size();j++){
            d[i][j] = min(d[i][j],d[i][u] + d[u][v] + d[v][j]);

            //u-v same as v-u
            d[i][j] = min(d[i][j],d[i][v] + d[v][u] + d[u][j]);

            sum+=d[i][j];
        }
    }

    return sum/2;
}

void solve() {
    int n;
    cin >> n;

    vector<vector<long long>> d(n,vector<long long>(n));
    //given shortest dist and all connected
    //two way connected
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> d[i][j];
        }
    }
    int k;
    cin >> k;

    for(int i=0;i<k;i++){
        int u,v,c;
        cin >> u >> v >> c;

       cout << sum_short_dist(d,u-1,v-1,c) << " ";
    }
}

int32_t main() {
    fast_io();

    // single test case:
    solve();

    // multiple test cases:
    // int t; cin >> t; while(t--) solve();

    return 0;
}