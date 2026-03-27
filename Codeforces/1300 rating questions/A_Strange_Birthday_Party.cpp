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
    int n,m;
    cin >> n >> m;

    map<int,int> mp;

    for(int i=0;i<n;i++){
        int k;cin >> k;
        mp[k]++;
    }

    vector<pair<int,int>> costs(m);

    for(int i=1;i<=m;i++){
        cin >> costs[i-1].ff;
        costs[i-1].ss = i;
    }

    sort(rall(costs));

    int l=0,r=m-1;
    ll cost=0;

    while(l<r){
        while(l<r && !mp.count(costs[l].ss)) l++;
        if(l>=r){
            break;
        }
        
        if(mp.count(costs[r].ss)){
            cost+=1ll*mp[costs[r].ss]*costs[r].ff;
        }

        cost+=1ll*costs[r].ff;
        r--;
        if(mp[costs[l].ss]==1){
            l++;
        }else{
            mp[costs[l].ss]--;
        }
    }

    if(l==r && mp.count(costs[r].ss)){
        cost+=1ll*mp[costs[r].ss]*costs[r].ff;
    }

    cout << cost << "\n";

}

int32_t main() {
    fast_io();

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}