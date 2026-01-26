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

const int MOD = 1e9 + 7;
const ll INF = 1e18;
const int N = 2e5 + 5;

void solve() {
    // Your code here
    int n;
    cin >> n;
    unordered_map<int,int> mp; 
    vector<int> ct(n+1,0);

    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        mp[a]++;
    }

    for(auto& [i,freq]:mp){
        for(int j=i;j<=n;j+=i){
            ct[j]+=freq;
        }
    }

    int max_frogs = 0,pos=0;

    for(int i=1;i<=n;i++){
        if(max_frogs<ct[i]){
            max_frogs = ct[i];
            pos=i;
        }
    }

    cout << max_frogs << "\n";
}

int32_t main() {
    fast_io();

    // single test case:
    // solve();

    // multiple test cases:
    int t; cin >> t; while(t--) solve();

    return 0;
}