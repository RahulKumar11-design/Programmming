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

    vpi a(n);ll sum=0;
    for(int i=0;i<n;++i){
        cin >> a[i].ff;
        a[i].ss = -1;
        sum+=a[i].ff;
    }

    pii global_st = {-1,-2};

    for(int i=0;i<q;i++){
        int t;cin >> t;

        if(t==1){
            int idx,x;
            cin >> idx >> x;
            int latest_val = (a[idx-1].ss>global_st.ss?a[idx-1].ff:global_st.ff);
            sum = sum-latest_val+x;
            a[idx-1] = {x,i};//new value,time stamp
        }else{
            int x;cin >> x;
            sum = 1ll*n*x;
            global_st = {x,i};
        }

        cout << sum << endl;
    }
}

int32_t main() {
    fast_io();

    //single test case
    solve();

    //multiple test case
    // int t;
    // cin >> t;
    // while (t--) solve();

    return 0;
}