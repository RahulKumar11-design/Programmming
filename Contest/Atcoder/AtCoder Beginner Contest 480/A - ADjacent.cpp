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
    int i1=-1,j1,i2,j2;

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            char c;
            cin >> c;

            if(c=='A' || c=='D'){
                if(i1==-1){
                    i1 = i;
                    j1 = j;
                }else{
                    i2 = i;
                    j2 = j;
                }
            }
        }
    }

    if(i1+1==i2 && j1+1==j2){
        cout << "No";
    }else if(i1+1==i2 && j1-1==j2){
        cout << "No";
    }else{
        cout << "Yes";
    }

    
}

int32_t main() {
    fast_io();

    // single test case:
    solve();

    // multiple test cases:
    // int t;
    // cin >> t;
    // while (t--) solve();

    return 0;
}