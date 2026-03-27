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
    int n;
    cin >> n;

    vi pos(n+1);
    for(int i=0;i<n;++i){
        int x;cin >> x;
        pos[x] = i+1;
    }
    ll ans=0;
    set<int> st;
    st.insert(-1);st.insert(0);
    st.insert(n+1);st.insert(n+2);

    for(int x=n;x>=1;x--){
        auto idx = st.lower_bound(pos[x]);

        int l1 = *prev(idx),l2 = *prev(prev(idx));
        int r1 = *idx,r2 = *next(idx);

        ll sum = 0;
        if(l1>0){
            // l1 x -> x 2nd max
            sum+=1ll*(l1-l2)*(r1-pos[x]);
        }
        if(r1<=n){
            //r1 x -> x 2nd max
            sum+=1ll*(r2-r1)*(pos[x]-l1);
        }

        ans+=sum*x;

        st.insert(pos[x]);
    }

    cout << ans << endl;
}

int32_t main() {
    fast_io();

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}