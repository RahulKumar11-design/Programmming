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

    vi v(1001,-1);
    rep(i, n){
        int x;
        cin >> x;
        v[x] = i+1;
    }

    int maxi = -1;

    if(v[1]!=-1){
        maxi = v[1]+n;
    }

    for(int a=2;a<1000;a++){
        if(v[a]==-1) continue;
        for(int b=a+1;b<1001;b++){
            if(v[b]==-1) continue;

            if(maxi<v[a]+v[b] && __gcd(a,b)==1){
                maxi = v[a]+v[b];
            }
        }
    }
    
    cout << maxi << "\n";
}

int32_t main() {
    fast_io();

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}