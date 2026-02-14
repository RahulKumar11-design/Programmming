#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

// loop macros
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i <= (n); i++)
#define repr(i, n) for (int i = (n)-1; i >= 0; i--)
#define repab(i, a, b) for (int i = (a); i <= (b); i++)
#define repba(i, b, a) for (int i = (b); i >= (a); i--)

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
    int n,k;
    cin >> n >> k;

    vector<vector<int>> mat(n,vector<int>(n));

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> mat[i][j];

    int unequal = 0;

    for(int i=0;i<n/2;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]!=mat[n-1-i][n-1-j]){
                unequal++;
            }
        }
    }

    if(n%2){
        for(int j=0;j<n/2;j++){
            if(mat[n/2][j]!=mat[n/2][n-1-j]){
                unequal++;
            }
        }
    }

    if(unequal<=k){
        if(n%2){
            yes;
        }else if(n%2==0 && (k-unequal)%2==0){
            yes;
        }else{
            no;
        }
    }else{
        no;
    }
    
}

int32_t main() {
    fast_io();

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}