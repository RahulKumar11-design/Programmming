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

bool predicate_fn(vector<int>& workloads,int k,ll goal){
    ll curr_load=0;int workers=1;

    for(int work:workloads){
        if(curr_load+work<=goal){
            curr_load+=work;
        }else{
            if(workers==k || work>goal){
                return false;
            }
            workers++;
            curr_load=work;
        }
    }

    return true;
}

void solve() {
    // Your code here
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    ll sum = accumulate(v.begin(),v.end(),0LL);
    int maxi = *max_element(v.begin(),v.end());

    ll low=maxi,high=sum,ans=sum;

    while(low<=high){
        ll mid = low+(high-low)/2;

        if(predicate_fn(v,k,mid)){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }

    cout << ans << "\n";

}

int32_t main() {
    fast_io();

    // single test case:
    solve();

    // multiple test cases:
    // int t; cin >> t; while(t--) solve();

    return 0;
}