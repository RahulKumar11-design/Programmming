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
    ll k,x;
    cin >> k >> x;

    ll total = k*k;

    if(x>=total){
        cout << 2*k-1 << "\n";
        return;
    }
    //increasing part
    ll m = ceil((-1+sqrt(1+8*x))/2);

    if(m<=k){
        cout << m << endl;
        return;
    }

    x-=k*(k+1)/2;

    ll b = 2*k-1;
    m = ceil((b-sqrt(b*b-8*(x)))/2);//smaller root < k

    cout << k+m << endl;
}

int32_t main() {
    fast_io();

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}