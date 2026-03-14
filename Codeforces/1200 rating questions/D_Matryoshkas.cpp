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
    int ai;
    map<int,int> mp; 
    for(int i=0;i<n;++i){
        cin >> ai;

        mp[ai]++;
    }

    ll ct=0;
    pii prev = {-2,0};

    for(auto &[key,freq]:mp){
        if(prev.ff+1!=key){
            ct+=prev.ss;
        }else if(freq<prev.ss){
            ct+=prev.ss-freq;
        }
        prev = {key,freq};
    }
    ct+=prev.ss;

    cout << ct << endl;
}

int32_t main() {
    fast_io();

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}