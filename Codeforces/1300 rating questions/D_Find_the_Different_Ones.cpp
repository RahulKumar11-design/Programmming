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

    vi a(n);
    for(int i=0;i<n;++i) cin >> a[i];

    set<int> st;

    for(int i=1;i<n;i++){
        if(a[i-1]!=a[i]){
            st.insert(i+1);
        }
    }

    int q;cin >> q;

    while(q-->0){
        int l,r;
        cin >> l >> r;

        auto it = st.lower_bound(l);

        if(it!=st.end() && *it<r && *it -1 >=l){
            cout << *it-1 << " " << *it << endl;
            continue;
        }

        it = st.upper_bound(r);

        if(it!=st.begin()){
            it--;

            if(l<=*it-1 && *it<=r){
                cout << *it-1 << " " << *it << endl;
                continue;
            }
        }

        cout << "-1 -1\n";
    }
    cout << endl;
}

int32_t main() {
    fast_io();

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}