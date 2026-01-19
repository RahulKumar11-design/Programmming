#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

#define yes cout << "YES\n"
#define no cout << "NO\n"

bool bfs(int src,vector<int>& color,vector<vector<int>>& adj){
    queue<pair<int,int>> q;
    q.push({src,0});
    color[src]=0;

    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        int nbr_color = (curr.second+1)%2;
        
        for(int nbr:adj[curr.first]){
            if(color[nbr]==-1){
                color[nbr] = nbr_color;
                q.push({nbr,nbr_color});
            }else if(color[nbr]!=nbr_color){
                return false;
            }
        }
    }

    return true;
}

void solve() {
    int n,m;
    cin >> n >> m;

    vector<vector<int>> edges(m);
    vector<vector<int>> adj(n+1);

    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        edges[i] = {u,v};

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> color(n+1,-1);

    if(!bfs(1,color,adj)){
        no;
    }else{
        yes;

        for(int i=0;i<m;i++){
            cout << color[edges[i][1]]; 
        }
    }
}

int main() {
    solve();
    return 0;
}