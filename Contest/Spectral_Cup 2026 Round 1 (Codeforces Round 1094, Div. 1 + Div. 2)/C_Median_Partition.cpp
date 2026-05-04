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

    for(int i:a){
        st.insert(i);
    }
    int maxi = 0;

    for(auto &x:st){
        vector<int> prefix(n+1,0);
        for(int i=1;i<=n;i++){
            prefix[i] = prefix[i-1]+a[i-1]-x;
        }
        vector<int> dp(n+1,0);

        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                if((i-j)%2==1){
                    if(prefix[i]-prefix[j]==0){
                        int sub = dp[j]+1;
                        dp[i] = max(dp[i],sub);
                    }
                }
            }
        }
        maxi = max(maxi,dp[n]);
    }

    cout << maxi << endl;
}

int32_t main() {
    fast_io();

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}