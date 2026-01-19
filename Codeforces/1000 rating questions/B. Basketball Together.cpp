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
    int n,D;
    cin >> n >> D;

    vector<int> p(n);

    for(int i=0;i<n;i++){
        cin >> p[i];
    }

    sort(p.begin(),p.end());

    int low=-1,high=p.size()-1;
    int cnt=0;
    while(low<high){
        ll players=1;
        while(low<high && players*p[high]<=D){
            low++;
            players++;
        }
        if(low<high){
            cnt++;
            high--;
        }
    }

    cout << cnt << endl;
}

int32_t main() {
    fast_io();

    // single test case:
    solve();

    // multiple test cases:
    // int t; cin >> t; while(t--) solve();

    return 0;
}