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
    vector<int> hop_length(n); 
    vector<int> freq(n+1,0);//max n = 2e5 
    vector<int> trapped_frogs(n+1,0);

    for(int i=0;i<n;i++){
        cin >> hop_length[i];
        if(hop_length[i]<=n) freq[hop_length[i]]++;
    }

    for(int h=1;h<=n;h++){
        for(int j=h;j<=n;j+=h){
            trapped_frogs[j]+=freq[h];
        }
    }

    int max_frogs=0;

    for(int i=1;i<=n;i++){
       max_frogs = max(max_frogs,trapped_frogs[i]);
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