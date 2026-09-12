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

bool fn(vector<vector<int>>& pref_bits,int l,int r,int k){
    int result = 0;

    for(int j=30;j>=0;j--){
        int bits = pref_bits[r][j]-pref_bits[l-1][j];

        if(bits==r-l+1){
            result|=(1<<j);
        }
    }

    return result>=k;
}

void solve() {
    // Your code here
    int n;
    cin >> n;

    vector<vector<int>> pref_bits(n+1,vector<int>(32,0));

    for (int i = 1; i <= n; i++){
        int ai;
        cin >> ai;

        for(int j=30;j>=0;j--){
            if(ai & (1<<j)){
                pref_bits[i][j] = 1+pref_bits[i-1][j];
            }else{
                pref_bits[i][j] = pref_bits[i-1][j];
            }
        }
    }

    int q;
    cin >> q;

    while(q--){
        int l,k;
        cin >> l >> k;

        int low = l, high = n, r = -1;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(fn(pref_bits,l,mid,k)){
                r = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }

        cout << r << " ";
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