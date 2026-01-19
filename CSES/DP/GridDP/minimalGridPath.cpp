#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

typedef pair<pair<char,string>,pair<int,int>> pp;

void solve(){
    int n;
    cin >> n;
    vector<vector<char>> grid(n,vector<char>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> dirs = {{-1,0},{0,-1},{0,1},{1,0}};
    vector<vector<bool>> vis(n,vector<bool>(n,false));
    priority_queue<pp,vector<pp>,greater<pp>> pq;
    string init = grid[0][0]+"";
    pq.push({{grid[0][0],init},{0,0}});

    string ans = "";

    while(!pq.empty()){
        pp curr = pq.top();
        pq.pop();

        string par = curr.first.second;
        int i = curr.second.first;
        int j = curr.second.second;
        vis[i][j] = true;

        if(i==n-1 && j==n-1){
            ans = par;
            break;
        }

        for(vector<int>& dir:dirs){
            int x = i+dir[0];
            int y = j+dir[1];

            if(x<0 || x>=n || y<0 || y>=n) continue;

            if(!vis[x][y]){
                string path = par+grid[x][y];

                pq.push({{grid[x][y],path},{x,y}});
            }
        }
    }

    cout << ans;
}

int main(){
    solve();
    return 0;
}