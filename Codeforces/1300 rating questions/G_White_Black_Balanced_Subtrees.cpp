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
int glob_ct;
int bal_subt(vector<vector<int>>& adj,string &s,int node){
    ll root_bal=(s[node-1]=='W'?1:-1);

    for(auto& nbr:adj[node]){
        root_bal+=bal_subt(adj,s,nbr);
    }

    if(root_bal==0){
        glob_ct++;
    }

    return root_bal;
}

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n+1);
    for(int i=2;i<=n;++i){
        int par;cin >> par;
        adj[par].push_back(i);
    }

    string s;cin >> s;
    glob_ct=0;

    bal_subt(adj,s,1);
    cout << glob_ct << endl;
}

int32_t main() {
    fast_io();

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}