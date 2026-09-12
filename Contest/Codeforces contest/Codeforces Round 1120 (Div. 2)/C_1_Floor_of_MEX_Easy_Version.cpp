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
    // Your code here
    int n;
    cin >> n;

    vector<int> diff(n+1,0);

    for(int i=1;i<=n;i++){
        int ai;cin >> ai;

        int l = ai*i;

        if(l<n){
            diff[l]++;
        }

        if((ai+1)*i<n){
            diff[(ai+1)*i]--;
        }

    }
    int m = (diff[0]>0)?0:1;

    for(int i=1;i<n;i++){
        diff[i]+=diff[i-1];

        if(diff[i]==0){
            m++;
        }
    }

    cout << m << endl;

    for(int i=0;i<n;i++){
        if(diff[i]==0){
            cout << i << " ";
        }
    }

    cout << endl;
}

int32_t main() {
    fast_io();

    // single test case:
    // solve();

    // multiple test cases:
    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}