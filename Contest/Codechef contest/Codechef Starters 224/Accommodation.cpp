#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

#ifdef LOCAL
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

const int MOD = 1e9 + 7;
const ll INF = 1e18;
const int N = 2e5 + 5;

bool fn(ll b,ll g,ll x,ll y,ll n,ll rooms){
    ll boys = rooms*x;
    ll girls = rooms*y;

    ll rem = rooms*(n-x-y);

    return rem>=(b+g-boys-girls);
}

void solve() {
    // Your code here
    int b,g,x,y,n;
    cin >> b >> g >> x >> y >> n;

    if(n<x+y){
        cout << "-1\n";
        return;
    }

    int low=1,high,ans=-1;
    int boys = b/x;
    int girls = g/y;

    high = min(boys,girls);

    while(low<=high){
        int mid = low+(high-low)/2;

        if(fn(b,g,x,y,n,mid)){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }


    cout << ans << "\n";
    
}

int32_t main() {
    fast_io();

    // single test case:
    // solve();

    // multiple test cases:
    int t; cin >> t; while(t--) solve();

    return 0;
}