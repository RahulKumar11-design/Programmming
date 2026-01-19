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
    vector<int> a(n);

    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[a[i]]=i%2;
    }

    sort(a.begin(),a.end());

    for(int i=0;i<n-1;i++){
        if(mp[a[i]]==mp[a[i+1]]){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    
}

int32_t main() {
    fast_io();

    // single test case:
    // solve();

    // multiple test cases:
    int t; cin >> t; while(t--) solve();

    return 0;
}