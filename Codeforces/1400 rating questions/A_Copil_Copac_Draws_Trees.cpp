#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

// container & utility macros
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second

// type shortcuts
using ll  = long long;
using vi  = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vpi = vector<pii>;

// algorithm helpers
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

// output shortcuts
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

const int MOD = 1e9 + 7;
const ll INF = 1e18;
const int N = 2e5 + 5;

int dfs(vector<vector<pii>>& adj,vector<bool>& vis,int u,int prev,int itrs){
    int maxi = itrs;
    vis[u] = true;

    for(auto& [v,idx]:adj[u]){
        if(vis[v]) continue;

        int tot_itrs;

        if(prev>idx){
            tot_itrs = dfs(adj,vis,v,idx,itrs+1);
        }else{
            tot_itrs = dfs(adj,vis,v,idx,itrs);
        }

        maxi = max(maxi,tot_itrs);
    }

    return maxi;
}

void solve() {
    // Your code here
    int n;
    cin >> n;

    vector<vector<pii>> adj(n+1);

    for (int i = 0; i < n-1; i++){
        int u,v;
        cin >> u >> v;

        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
    }

    vector<bool> vis(n+1,false);

    cout << dfs(adj,vis,1,-1,1) << endl;
    
}

int32_t main() {
    fast_io();

    // single test case:
    // solve();

    // multiple test cases:
    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}