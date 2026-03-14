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
    int n,k,p,m;
    cin >> n >> k >> p >> m;

    vi a(n);
    for(int i=0;i<n;++i) cin >> a[i];

    if(k==n){
        cout << m/a[p-1] << endl;
        return;
    }

    priority_queue<int,vector<int>,greater<int>> pq;

    for(int i=0;i<p-1;i++){
        pq.push(a[i]);
    }

    ll inst1 = a[p-1];

    int need = max(p,k);

    int req_ele = need-k;

    while(req_ele-->0){
        inst1+=pq.top();
        pq.pop();
    }

    for(int i=p;i<n;i++){
        pq.push(a[i]);
    }

    req_ele = n-need;

    int inst2 = 0;

    while(req_ele-->0){
        inst2+=pq.top();
        pq.pop();
    }

    if(inst1>m){
        cout << "0\n";
    }else{
        cout << 1 + (m-inst1)/(inst1+inst2) << endl;
    }

}

int32_t main() {
    fast_io();

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}