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
    int n,h,l;
    cin >> n >> h >> l;
    vector<int> a(n);

    for(int i=0;i<n;i++) cin >> a[i];

    int mini = min(l,h);
    int maxi = max(l,h);

    int el1=0,el2=0;

    for(int i=0;i<n;i++){
        if(a[i]<=mini){
            el1++;
        }else if(a[i]<=maxi){
            el2++;
        }
    }

    if(el1<=el2){
        cout << el1 << "\n";
    }else{
        cout << el2 + (el1-el2)/2 << "\n";
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