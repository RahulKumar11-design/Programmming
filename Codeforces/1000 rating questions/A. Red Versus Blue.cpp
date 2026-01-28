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
    int n,r,b;
    cin >> n >> r >> b;

    string s = "";

    while(b>0){
        int div = ceil((1.0f*r)/(b+1));
        if(r<div){
            for(int i=0;i<r;i++) s+='R';
            r=0;
            for(int i=0;i<b;i++) s+='B';
            b=0;
            break;
        }


        for(int i=0;i<div;i++) s+='R';
        r-=div;

        s+='B';b--;
    }

    if(r>0){
        for(int i=0;i<r;i++) s+='R';
        r=0;
    }

    cout << s << "\n";
}

int32_t main() {
    fast_io();

    // single test case:
    // solve();

    // multiple test cases:
    int t; cin >> t; while(t--) solve();

    return 0;
}