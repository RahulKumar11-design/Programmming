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
    string s;
    cin >> s;

    vector<int> pref(n),suff(n);
    unordered_set<char> st;

    pref[0]=1;st.insert(s[0]);

    for(int i=1;i<n;i++){
        if(st.count(s[i])){
            pref[i]=pref[i-1];
        }else{
            st.insert(s[i]);
            pref[i]=1+pref[i-1];
        }
    }
    st.clear();

    suff[n-1]=1;
    st.insert(s[n-1]);
    
    for(int i=n-2;i>=0;i--){
        if(st.count(s[i])){
            suff[i]=suff[i+1];
        }else{
            st.insert(s[i]);
            suff[i]=1+suff[i+1];
        }
    }

    int maxi = 0;

    for(int i=0;i<n-1;i++){
        int tot = pref[i]+suff[i+1];

        maxi = max(maxi,tot);
    }

    cout << maxi << endl;
}

int32_t main() {
    fast_io();

    // single test case:
    // solve();

    // multiple test cases:
    
    int t; cin >> t; while(t--) solve();

    return 0;
}