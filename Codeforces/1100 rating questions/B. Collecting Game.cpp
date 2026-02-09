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
    vector<pair<int,int>> nums(n);

    for(int i=0;i<n;i++){
        cin >> nums[i].first;
        nums[i].second = i;
    }

    sort(all(nums));

    vector<ll> pre(n);
    pre[0] = nums[0].first;
    
    for(int i=1;i<n;i++){
        pre[i] = nums[i].first+pre[i-1];
    }

    vector<int> ans(n);
    ans[nums[n-1].second] = n-1;

    for(int i=n-2;i>=0;i--){
        ans[nums[i].second] = (pre[i]>=nums[i+1].first?ans[nums[i+1].second]:i);
    }

    for(int e:ans) cout << e << " ";
    cout << "\n";
    
}

int32_t main() {
    fast_io();

    // single test case:
    // solve();

    // multiple test cases:
    int t; cin >> t; while(t--) solve();

    return 0;
}