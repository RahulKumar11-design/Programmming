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

void solve() {
    // Your code here
    int n,k;
    cin >> n >> k;

    if(k<n || k==2*n){
        cout << "-1\n";
        return;
    }

    vector<vector<int>> v(n+1,vector<int>(n+1,-1));

    for(int i=2;i<=n;i++){
        v[i][1] = n+i-1;
    }

    int d = 2*n-k;

    for(int i=1;i<=d;i++){
        v[i][i] = i;
    }

    for(int i=d+1;i<=n;i++){
        v[1][i] = i;
    }

    int st = 2*n;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(v[i][j]==-1){
                v[i][j] = st++;
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
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