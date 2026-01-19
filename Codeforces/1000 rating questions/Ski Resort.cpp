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
const int INF = 1e18;
const int N = 2e5 + 5;

void solve() {
    // Your code here
    int n,k,q;
    cin >> n >> k >> q;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    int w=0;
    ll ways = 0;

    for(int i=0;i<n;i++){
        if(arr[i]<=q){
            w++;
        }else{
            if(w>=k){
                ways+=(w-k+1)*(w-k+2)/2;
            }
            w=0;
        }
    }
    if(w>=k){
        ways+=(w-k+1)*(w-k+2)/2;
    }

    cout << ways << endl;
}

int32_t main() {
    fast_io();

    // single test case:
    // solve();

    // multiple test cases:
    int t; cin >> t; while(t--) solve();

    return 0;
}