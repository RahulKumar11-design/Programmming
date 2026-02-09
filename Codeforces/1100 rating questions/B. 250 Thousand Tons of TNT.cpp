#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

// loop macros
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i <= (n); i++)
#define repr(i, n) for (int i = (n)-1; i >= 0; i--)
#define repab(i, a, b) for (int i = (a); i <= (b); i++)
#define repba(i, b, a) for (int i = (b); i >= (a); i--)

// container & utility macros
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ff first
#define ss second

// type shortcuts
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int,int>
#define pll pair<long long,long long>
#define vpi vector<pair<int,int>>

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

#ifdef LOCAL
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

const int MOD = 1e9 + 7;
const ll INF = 1e18;
const int N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;

    vi a(n);
    rep(i, n) cin >> a[i];

    vll pre(n);
    pre[0]=a[0];

    repab(i,1,n-1){
        pre[i] = a[i]+pre[i-1];
    }

    ll maxi_diff = 0;

    for(int k=1;k*k<=n;k++){
        if(n%k!=0) continue;
        ll maxi = 0, mini=pre[n-1];

        for(int i=0;i<n-k+1;i+=k){
            ll sum = pre[i+k-1]-(i>0?pre[i-1]:0);

            mini = min(mini,sum);
            maxi = max(maxi,sum);
        }
        ll diff = maxi-mini;
        maxi_diff = max(maxi_diff,diff);

        int k2 = n/k;
        maxi = 0, mini=pre[n-1];

        for(int i=0;i<n-k2+1;i+=k2){
            ll sum = pre[i+k2-1]-(i>0?pre[i-1]:0);

            mini = min(mini,sum);
            maxi = max(maxi,sum);
        }
        diff = maxi-mini;
        maxi_diff = max(maxi_diff,diff);
    }

    cout << maxi_diff << "\n";
}

int32_t main() {
    fast_io();

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}