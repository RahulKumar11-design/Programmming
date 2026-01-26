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

void solve() {
    // Your code here
    ll n,x;
    cin >> n >> x;

    ll ai,bi,ci,max_di;
    cin >> ai >> bi >> ci;
    max_di = ai*bi-ci;
    x-=ai*(bi-1);

    for(int i=1;i<n;i++){
        cin >> ai >> bi >> ci;
        ll di = ai*bi-ci;
        max_di = max(max_di,di);
        x-=ai*(bi-1);
    }
    
    if(x<=0){
        cout << "0\n";
    }else{
        if(max_di<=0){
            cout << "-1\n";
        }else{
            cout << (x+max_di-1)/max_di << "\n";
        }
    }
}

int32_t main() {
    fast_io();

    // single test case:
    // solve();

    // multiple test cases:
    int t; cin >> t; while(t--) solve();

    return 0;
}