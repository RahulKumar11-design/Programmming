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

    vector<vector<int>> v(n);
    for(int i=0;i<n;++i) {
        int ki;cin >> ki;

        for(int j=0;j<ki;j++){
            int ai;cin >> ai;
            v[i].push_back(ai);
        }
    }

    vector<pair<int,int>> maxis;

    for(int i=0;i<n;i++){
        int maxi = v[i][0]+1;
        for(int j=1;j<v[i].size();j++){
            if(maxi<=v[i][j]-j){
                maxi = v[i][j]-j+1;
            }
        }
        maxis.push_back({maxi,v[i].size()});
    }

    sort(all(maxis));

    int start = maxis[0].ff,incre=maxis[0].ss;

    for(int i=1;i<n;i++){
        if(maxis[i].ff-incre>start){
            start = maxis[i].ff-incre;
        }
        incre+=maxis[i].ss;
    }

    cout << start << "\n"; 

}

int32_t main() {
    fast_io();

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}