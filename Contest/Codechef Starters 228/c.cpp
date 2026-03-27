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
    int n,k;
    cin >> n >> k;

    vi b(n);
    for(int i=0;i<n;++i) cin >> b[i];



    int prev = 0,mini=n+1;

    for(int i=1;i<=n;i++){
        if(b[i-1]==1){
            if(prev!=0){
                int diff = i-prev;
                mini = min(mini,diff);
            }
            prev = i;
        }
    }

    if(prev==0 || mini<=k){
        no;
    }else{ 
        prev = 1;
        for(int i=1;i<=n;i++){
            if(b[i-1]==1){
                if(i-k<=prev){
                    prev = i+k+1;
                }else{
                    no;
                    return;
                }
            }
        }
        if(prev<=n){
            no;
        }else{
            yes;
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