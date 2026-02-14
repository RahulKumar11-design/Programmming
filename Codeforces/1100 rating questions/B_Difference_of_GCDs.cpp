#include <bits/stdc++.h>
using namespace std;

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
    int n,l,r;
    cin >> n >> l >> r;

    vi ans(n);
    ans[0]=l;

    for(int i=2;i<=n;i++){
        if(l<=r-r%i){
            ans[i-1]=r-r%i;
        }else{
            no;
            return;
        }
    }
    yes;

    for(int g:ans) cout << g << " ";

    cout << endl;
}

int32_t main() {
    fast_io();

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}