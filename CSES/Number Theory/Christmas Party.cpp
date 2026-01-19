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

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const ll N = 2e5 + 5;

void solve() {
    // Your code here
    int n;
    cin >> n;

    if(n==1){
        cout << "0\n";
        return;
    }
    ll ans;
    if(n%2==0){
        ans=1;
    }else{
        ans=-1;
    }
    ll fact=1;

    for(int i=n;i>=3;i--){
        fact=(fact*i)%MOD; 
        if((i-1)%2==0){
            ans=(ans+fact)%MOD;
        }else{
            ans=(ans-fact+MOD)%MOD;
        }
    }

    cout << ans << "\n";
}

int32_t main() {
    fast_io();

    // single test case:
    solve();

    // multiple test cases:
    // int t; cin >> t; while(t--) solve();

    return 0;
}