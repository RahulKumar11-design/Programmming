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
    int n,q;
    cin >> n >> q;

    vi a(n);
    for(int i=0;i<n;++i) cin >> a[i];

    if(n == 1){
        while(q--){
            int x; cin >> x;
            cout << x << endl;
        }
        return;
    }
    
    sort(all(a));
    vector<int> diffs;

    for(int i=1;i<n;i++){
        diffs.push_back(a[i]-a[i-1]);
    }

    sort(all(diffs));

    vector<ll> prefix(n-1);
    
    prefix[0]=diffs[0];
    for(int i=1;i<n-1;i++){
        prefix[i] = prefix[i-1]+diffs[i];
    }

    while(q--){
        int x;cin >> x;

        int idx = lower_bound(all(diffs), x) - diffs.begin();

        ll ans = 1ll*(n-1-idx)*x+x;

        if(idx>0){
            ans+=prefix[idx-1];
        }

        cout << ans << "\n";
    }
}

int32_t main() {
    fast_io();

    solve();
    // int t;
    // cin >> t;
    // while (t--) solve();

    return 0;
}