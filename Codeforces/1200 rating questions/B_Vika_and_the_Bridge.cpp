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

/* ================= DEBUG UTILITIES ================= */
// command - g++ -DLOCAL file.cpp
#ifdef LOCAL
#define debug(x) cerr << #x << " = "; _print(x); cerr << '\n';
#else
#define debug(x)
#endif

void _print(int x) { cerr << x; }
void _print(long long x) { cerr << x; }
void _print(char x) { cerr << x; }
void _print(string x) { cerr << x; }
void _print(bool x) { cerr << (x ? "true" : "false"); }

template<class T, class V>
void _print(pair<T, V> p) {
    cerr << "{ ";
    _print(p.first);
    cerr << ", ";
    _print(p.second);
    cerr << " }";
}

template<class T>
void _print(vector<T> v) {
    cerr << "[ ";
    for (auto &x : v) {
        _print(x);
        cerr << " ";
    }
    cerr << "]";
}

template<class T>
void _print(set<T> s) {
    cerr << "{ ";
    for (auto &x : s) {
        _print(x);
        cerr << " ";
    }
    cerr << "}";
}

template<class T, class V>
void _print(map<T, V> m) {
    cerr << "{ ";
    for (auto &x : m) {
        _print(x);
        cerr << " ";
    }
    cerr << "}";
}
/* ================= END DEBUG UTILITIES ================= */

const int MOD = 1e9 + 7;
const ll INF = 1e18;
const int N = 2e5 + 5;

void solve() {
    int n,k;
    cin >> n >> k;

    map<int,stack<int>> mp;

    for(int i=1;i<=n;i++){
        int temp;cin >> temp;
        mp[temp].push(i);
    }

    int mini = n;
    
    for(auto [col,st]:mp){
        vector<int> v(st.size()+1);
        v[v.size()-1] = n-st.top();
        int last = st.top();st.pop();
        for(int i=v.size()-2;i>=1;i--){
            v[i] = last-st.top()-1;
            last = st.top();st.pop();
        }
        v[0] = last-1;

        sort(rall(v));

        v[0]/=2;

        int maxi = max(v[0],v[1]);
        mini = min(mini,maxi);
    }

    cout << mini << endl;
}

int32_t main() {
    fast_io();

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}