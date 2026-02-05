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
    int a,b;
    cin >> a >> b;

    int op=0;

    while(a>0){
        //greedy
        if(b==1){
            b++;op++;
            continue;
        }

        int op1 = log(a)/log(b) +1;
        int op2 = log(a)/log(b+1) +2;

        if(op1<op2){
            a/=b;
        }else{
            b++;
        }
        op++;
    }

    cout << op << "\n";
}

int32_t main() {
    fast_io();

    // single test case:
    // solve();

    // multiple test cases:
    int t; cin >> t; while(t--) solve();

    return 0;
}