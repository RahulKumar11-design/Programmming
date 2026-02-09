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
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    int sum=a[0],maxi=a[0];
    bool parity = (2+a[0]%2)%2;

    for(int i=1;i<n;i++){
        if(parity==(2+a[i]%2)%2 || sum<0){
            sum = a[i];
        }else{
            sum+=a[i];
        }
        parity=(2+a[i]%2)%2;
        maxi = max(maxi,sum);
    }

    cout << maxi << "\n";
}

int32_t main() {
    fast_io();

    // single test case:
    // solve();

    // multiple test cases:
    int t; cin >> t; while(t--) solve();

    return 0;
}