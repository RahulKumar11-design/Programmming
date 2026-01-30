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

    vector<int> a(n);
    bool isSorted = true;
    for(int i=0;i<n;i++) cin >> a[i];

    for(int i=1;i<n;i++){
        if(a[i-1]>a[i]){
            isSorted = false;
            break;
        }
    }

    if(isSorted){
        cout << "-1\n";
        return;
    }
    vector<int> b(a);

    sort(all(a));

    //delete placed
    vector<int> v;
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]){
            v.push_back(a[i]);
        }
    }
    int m = v.size();

    int mini = a[n-1]-a[0];

    for(int i=0;i<m;i++){
        int d1 = v[i]-a[0];
        int d2 = a[n-1]-v[i];

        int maxi = max(d1,d2);

        mini = min(mini,maxi);
    }

    cout << mini << "\n";
}

int32_t main() {
    fast_io();

    // single test case:
    // solve();

    // multiple test cases:
    int t; cin >> t; while(t--) solve();

    return 0;
}