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
    string s;
    cin >> s;

    int tot=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1') tot++;
    }
    if(tot==0){
        cout << (n+2)/3 << "\n";
        return;
    }

    int l=-1;

    for(int r=0;r<n;r++){
        if(s[r]=='1'){
            int len;
            if(l==-1){
                len = r-1;
            }else{
                len = r-l-3;
            }

            tot+=(len+2)/3;

            l=r;
        }
    }
    int len = n-l-2;
    tot+=(len+2)/3;

    cout << tot << "\n";
}

int32_t main() {
    fast_io();

    // single test case:
    // solve();

    // multiple test cases:
    int t; cin >> t; while(t--) solve();

    return 0;
}