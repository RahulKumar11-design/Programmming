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

bool fn(ll n,ll x){
    ll ct=min(n,x);

    for(int i=2;i<=n;i++){
        ll range = x/i; 
        ct+=min(range,n);
    }

    return ct>=(n*n/2 + 1);
}

void solve() {
    // Your code here
    int n;
    cin >> n;

    ll low=1,high=1ll*n*n,ans=1ll*n*n;

    while(low<=high){
        ll mid = low+(high-low)/2;

        if(fn(n,mid)){
            ans = min(ans,mid);
            high = mid-1;
        }else{
            low = mid+1;
        }
    }

    cout << ans;
}

int32_t main() {
    fast_io();

    // single test case:
    solve();

    // multiple test cases:
    // int t; cin >> t; while(t--) solve();

    return 0;
}