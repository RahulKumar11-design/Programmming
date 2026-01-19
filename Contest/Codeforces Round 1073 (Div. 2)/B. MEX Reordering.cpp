#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

#ifdef LOCAL
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const ll N = 2e5 + 5;

void solve() {
    // Your code here
    int n;
    cin >> n;
    vector<int> v(n+1,0);

    for(int i=0;i<n;i++){
        int x;cin >> x;
        v[x]++;
    }

    if(v[0]==0){
        cout << "NO\n";
    }else if(v[0]==1){
        cout << "YES\n";
    }else{
        if(v[1]>0){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}

int32_t main() {
    fast_io();

    // single test case:
    // solve();

    // multiple test cases:
    int t; cin >> t; while(t--) solve();

    return 0;
}