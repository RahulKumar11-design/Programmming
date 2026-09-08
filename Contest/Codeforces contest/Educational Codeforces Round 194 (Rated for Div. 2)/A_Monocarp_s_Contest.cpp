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
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    if(a[0]==0 && a[n-1]==0){
        cout << "0\n";
        return;
    }

    int ct=0;

    for(int i=1;i<n-1;i++){
        if(a[i]==0){
            ct++;
        }
    }

    int req = 0;

    if(a[0]==1){
        req++;
    }

    if(a[n-1]==1){
        req++;
    }

    if(req<=ct){
        cout << req << "\n";
    }else{
        cout << "-1\n";
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