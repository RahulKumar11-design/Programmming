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
int N = 1e9;

void solve() {
    // Your code here
    int n;
    cin >> n;

    vector<int> a(n);

    for(int i=0;i<n;i++){
        cin >> a[i];
        a[i] = abs(a[i]);
    }

    sort(all(a));

    ll ct=0;

    for(int i=0;i<n-1;i++){
        int low=0,high=n-1;
        ll tar = 2ll*a[i];
        
        while(low<=high){
            int mid = low+(high-low)/2;

            if(a[mid]<=tar){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        ct+=low-1-i;
    }

    cout << ct;
}

int32_t main() {
    fast_io();

    // single test case:
    solve();

    // multiple test cases:
    // int t; cin >> t; while(t--) solve();

    return 0;
}