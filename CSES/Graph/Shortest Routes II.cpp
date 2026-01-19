#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

const ll unlinked = 1e18;

ll min(ll a,ll b){
    if(a<b) return a;
    else return b;
}

void solve() {
    int n,m,q;
    cin >> n >> m >> q;

    vector<vector<ll>> d(n,vector<ll>(n,unlinked));
    //init
    for(int i=0;i<n;i++){
        d[i][i] = 0;
    }
    for(int i=0;i<m;i++){
        int u,v,c;
        cin >> u >> v >> c;
        
        d[u-1][v-1] = min(d[u-1][v-1],c);
        d[v-1][u-1] = min(d[v-1][u-1],c);
    }

    vector<vector<int>> queries(q,vector<int>(2));

    for(int i=0;i<q;i++){
        int u,v;
        cin >> u >> v;

        queries[i][0] = u-1;
        queries[i][1] = v-1;
    }

    //Floyd Warshall Algo
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(d[i][k]==unlinked || d[k][j]==unlinked){
                    continue;
                }
                
                if(d[i][k]+d[k][j]<d[i][j]){
                    d[i][j] = d[i][k]+d[k][j];
                }
            }
        }
    }

    for(int i=0;i<q;i++){
        int u = queries[i][0];
        int v = queries[i][1];

        if(d[u][v]!=unlinked){
            cout << d[u][v] << "\n" ;
        }else{
            cout << "-1\n";
        }
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