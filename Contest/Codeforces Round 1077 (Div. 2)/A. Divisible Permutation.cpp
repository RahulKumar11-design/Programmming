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

    vector<int> v(n+1);

    v[n]=n;
    v[n-1]=1;
    unordered_set<int> st;
    
    for(int i=2;i<n;i++) st.insert(i);

    for(int i=n-2;i>=1;i--){
        if(st.count(v[i+1]+i)){
            v[i]=v[i+1]+i;
            st.erase(v[i+1]+i);
        }else if(st.count(v[i+1]-i)){
            v[i]=v[i+1]-i;
            st.erase(v[i+1]-i);
        }
    }

    for(int i=1;i<=n;i++) cout << v[i] << " ";
    cout << endl;
}

int32_t main() {
    fast_io();

    // single test case:
    // solve();

    // multiple test cases:
    int t; cin >> t; while(t--) solve();

    return 0;
}