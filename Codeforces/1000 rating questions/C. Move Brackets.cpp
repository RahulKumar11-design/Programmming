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

    stack<char> st;

    for(int r=n-1;r>=0;r--){
        if(s[r]=='('){
            if(!st.empty() && st.top()!='('){
                st.pop();
            }else{
                st.push(s[r]);
            }
        }else{
            st.push(s[r]);
        }
    }

    cout << st.size()/2 << "\n";
}

int32_t main() {
    fast_io();

    // single test case:
    // solve();

    // multiple test cases:
    int t; cin >> t; while(t--) solve();

    return 0;
}