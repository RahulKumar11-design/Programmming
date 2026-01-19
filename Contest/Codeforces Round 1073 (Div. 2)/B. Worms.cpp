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
    vector<int> a(n);//prefix==lables_end
    cin >> a[0];
    for(int i=1;i<n;i++){
        cin >> a[i];
        a[i]+=a[i-1];
    }
    int m;cin >> m;
    vector<int> q(m);
    for(int i=0;i<m;i++){
        cin >> q[i];
    }
    vector<int> ans(m);
    for(int i=0;i<m;i++){
        int low=0,high=n-1;
        while(low<=high){
            int mid = low+(high-low)/2;

            if(a[mid]>=q[i]){
                ans[i]=mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
    }
    //display pile no. in which tasty worms present
    for(int i=0;i<m;i++){
        cout << ans[i]+1 << "\n";//1 based index
    }
    
}

int32_t main() {
    fast_io();

    // single test case:
    solve();

    // multiple test cases:
    // int t; cin >> t; while(t--) solve();

    return 0;
}