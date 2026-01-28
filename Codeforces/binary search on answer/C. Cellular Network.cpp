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
    int n,m;
    cin >> n >> m;

    vector<int> a(n),b(m);

    for(int i=0;i<n;i++) cin >> a[i];
    for(int j=0;j<m;j++) cin >> b[j];

    vector<int> d(n);

    for(int i=0;i<n;i++){
        int city = a[i];
        int low=0,high=m-1;d[i]=abs(b[0]-city);

        while(low<=high){
            int mid = low + (high-low)/2;
            if(d[i]>abs(b[mid]-city)){
                d[i] = abs(b[mid]-city);
            }

            if(b[mid]==city){
                break;
            }else if(b[mid]<city){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
    }

    int ans = d[0];
    for(int i=1;i<n;i++) ans = max(ans,d[i]);

    cout  << ans;
}

int32_t main() {
    fast_io();

    // single test case:
    solve();

    // multiple test cases:
    // int t; cin >> t; while(t--) solve();

    return 0;
}