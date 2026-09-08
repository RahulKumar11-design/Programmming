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

int rec(int a,int b,int x,map<pair<int,int>,int> &dp){
    if(a==b){
        return 0;
    }
    int maxi = max(a,b);
    int mini = min(a,b);

    if(dp.count({maxi,mini})){
        return dp[{maxi,mini}];
    }

    int way1 = maxi-mini;

    int way2 = rec(maxi/x,mini,x,dp)+1;

    int way3 = rec(maxi/x,mini/x,x,dp)+2;

    int way = min(way1,way2);

    return dp[{maxi,mini}] = min(way,way3);
}

void solve() {
    int a,b,x;
    cin >> a >> b >> x;

    if(a==b){
        cout << "0\n";
        return;
    }
    map<pair<int,int>,int> dp;

    cout << rec(a,b,x,dp) << endl;
}

int32_t main() {
    fast_io();

    //solve();

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}