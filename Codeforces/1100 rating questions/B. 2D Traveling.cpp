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
    int n,k,a,b;
    cin >> n >> k >> a >> b;

    vll x(n),y(n);
    rep(i, n) cin >> x[i] >> y[i];

    if(a<=k && b<=k){
        cout << "0\n";
    }else if(a<=k || b<=k){
        ll min_cost = abs(x[a-1]-x[b-1])+abs(y[a-1]-y[b-1]);

        for(int i=1;i<=k;i++){
            if(a<=k){
                ll cost = abs(x[i-1]-x[b-1])+abs(y[i-1]-y[b-1]);
                min_cost = min(min_cost,cost);
            }else{
                ll cost = abs(x[a-1]-x[i-1])+abs(y[a-1]-y[i-1]);
                min_cost = min(min_cost,cost);
            }
        }

        cout << min_cost << "\n";
    }else{
        ll min_cost = abs(x[a-1]-x[b-1])+abs(y[a-1]-y[b-1]);
        
        ll min_cost_a = 1e17;
        for(int i=1;i<=k;i++){
            ll cost = abs(x[a-1]-x[i-1])+abs(y[a-1]-y[i-1]);
            min_cost_a = min(min_cost_a,cost);
        }

        ll min_cost_b = 1e17;
        for(int i=1;i<=k;i++){
            ll cost = abs(x[i-1]-x[b-1])+abs(y[i-1]-y[b-1]);
            min_cost_b = min(min_cost_b,cost);
        }

        if(min_cost<=min_cost_a+min_cost_b){
            cout << min_cost << "\n";
        }else{
            cout << min_cost_a+min_cost_b << "\n";
        }
    }
}

int32_t main() {
    fast_io();

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}