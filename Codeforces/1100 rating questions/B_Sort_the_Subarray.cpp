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
    int n;
    cin >> n;

    vi a(n),b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    bool same = a[0]==b[0];

    int l=0,r,j=0,maxlen=1;

    for(r=1;r<n;r++){
        if(b[r-1]<=b[r]){
            same&=a[r]==b[r];
        }else{
            if(!same && maxlen<=r-l){
                maxlen=r-l;
                j=r-1;
            }
            l=r;same=a[r]==b[r];
        }
    }
    if(!same && maxlen<=r-l){
        maxlen=r-l;
        j=r-1;
    }
    
    cout << (j+1-maxlen)+1 << " " << j+1 << endl;
}

int32_t main() {
    fast_io();

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}