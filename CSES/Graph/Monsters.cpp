#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    // Your code here
    int n,m;
    cin >> n >> m;

    vector<vector<int>> grid(n,vector<int>(m));
    queue<pair<int,int>> qA;
    queue<pair<int,int>> qM;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char temp;
            cin >> temp;
            if(temp=='#'){//wall
                grid[i][j] = -1;
            }else if(temp=='A'){//A
                qA.push({i,j});
                grid[i][j] = -2;
            }else if(temp=='M'){//monster
                qM.push({i,j});
                grid[i][j] = -2;
            }else{//.
                grid[i][j] = 0;
            }
        }
    }

    unordered_map<char,vector<int>> dirs;
    dirs['R'] = {0,1};
    dirs['L'] = {0,-1};
    dirs['D'] = {1,0};
    dirs['U'] = {-1,0};
    unordered_map<char,char> rev_sign;
    rev_sign['R'] = 'L';
    rev_sign['L'] = 'R';
    rev_sign['D'] = 'U';
    rev_sign['U'] = 'D';
    vector<vector<char>> par(n,vector<char>(m,'.'));
    
    
    //bfs
    int level = 1;

    while(!qA.empty()){
        int sizeM = qM.size();
        while(sizeM-->0){
            auto [i,j] = qM.front();
            qM.pop();

            for(auto [sign,dir]:dirs){
                int x = i+dir[0];
                int y = j+dir[1];

                if(x<0 || x>=n || y<0 || y>=m || grid[x][y]!=0) continue;

                grid[x][y] = level;
                qM.push({x,y});
            }
        }

        int sizeA = qA.size();

        while(sizeA-->0){
            auto curr = qA.front();
            qA.pop();

            if(curr.first==0 || curr.first==n-1 || curr.second==0 || curr.second==m-1){
                vector<char> ans;
                int i=curr.first,j=curr.second;

                while(par[i][j]!='.'){
                    vector<int> par_dir = dirs[par[i][j]];
                    char child_sign = rev_sign[par[i][j]];
                    ans.push_back(child_sign);
                    
                    i+=par_dir[0];
                    j+=par_dir[1];
                }

                cout << "YES\n";
                cout << ans.size() << "\n";

                for(int k=ans.size()-1;k>=0;k--){
                    cout << ans[k];
                }
                cout << "\n";
                return;
            }

            for(auto [sign,dir]:dirs){
                int x = curr.first+dir[0];
                int y = curr.second+dir[1];

                if(x<0 || x>=n || y<0 || y>=m || grid[x][y]!=0) continue;

                grid[x][y] = level;
                //sign for child to get to par
                par[x][y] = rev_sign[sign];
                qA.push({x,y});
            }
        }

        level++;
    }

    cout << "NO\n";
}

int32_t main() {
    fast_io();

    // single test case:
    solve();

    // multiple test cases:
    // int t; cin >> t; while(t--) solve();

    return 0;
}