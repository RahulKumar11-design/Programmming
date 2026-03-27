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

// void solve() {
//     int n;
//     cin >> n;

//     vi a(n);
//     for(int i=0;i<n;++i) cin >> a[i];

//     vector<pair<int,int>> dp(n);

//     dp[0].ff=a[0];
//     dp[0].ss=1;
//     ll fact = 1;
//     for(int i=1;i<n;i++){
//         if(dp[i-1].ff>=fact*(dp[i-1].ss+1)){
//             dp[i].ff=dp[i-1].ff*a[i];
//             dp[i].ss=dp[i-1].ss+1;
//             fact*=dp[i].ss;
//         }else{
//             dp[i].ff=a[i];
//             dp[i].ss=1;
//             fact=1;
//         }
//     }

//     for(int i=0;i<n;i++){
//         cout << dp[i].ss << " ";
//     }
//     cout << endl;
// }

void solve(){
    int n;
    cin >> n;

    vi a(n);

    for(int i=0;i<n;++i){
        cin >> a[i];
    }

    vector<int> ans(n);
    
    for(int i=0;i<n;i++){
        int l=1,r=i+1;

        while(l<=r){
            int m = l+(r-l)/2;
            //m len  am>=m---ar will be good
            if(a[i-m+1]>=m){
                l=m+1;
            }else{
                r=m-1;
            }
        }

        ans[i]=r;
    }

    for(int i=0;i<n;i++){
        cout << ans[i] << " ";
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