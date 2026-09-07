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

    long maxi = 0;

    for(int i=0;i<n;i++){
        long sum = a[i];
        int limit = a[i];

        for(int j=i-1;j>=0;j--){
            sum+=min(a[j],limit);
            limit = min(a[j],limit);
        }
        limit = a[i];

        for(int k=i+1;k<n;k++){
            sum+=min(a[k],limit);
            limit = min(a[k],limit);
        }

        maxi = max(maxi,sum);
    }

    cout << maxi << endl;

    
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