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

bool fn(vector<int>& a,int day,int m){
    int p=0;
    // cout << day << "\n";

    for(auto it:a){
        p+=it/day;

        if(p>=m){
            return true;
        }
    }

    return false;
}

void solve() {
    int n,m;
    cin >> n >> m;

    vi a(n);
    for(int i=0;i<n;++i) cin >> a[i];

    int low=1,high=a[0],ans=0;

    for(int i=1;i<n;i++){
        high = max(high,a[i]);
    }

    while(low<=high){
        int mid = low + (high-low)/2;

        if(fn(a,mid,m)){
            low = mid+1;
            ans = mid;
        }else{
            high = mid-1;
        }
    }

    cout << ans << endl;
}

int32_t main() {
    fast_io();

    solve();
    // int t;
    // cin >> t;
    // while (t--) solve();

    return 0;
}