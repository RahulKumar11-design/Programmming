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
    string a,b;
    cin >> a >> b;
    

    int max_size=0;

    for(int i=0;i<a.size();i++){
        for(int j=i;j<a.size();j++){
            int len = j-i+1;
            if(max_size>=len) continue;

            for(int k=0;k<sz(b)-len+1;k++){
                int l=0;

                for(;l<len;l++){
                    if(a[i+l]!=b[k+l]) break;
                }

                if(l==len){
                    max_size = max(max_size,len);
                }
            }
        }
    }

    cout << a.size()+b.size()-2*max_size << "\n";
}

int32_t main() {
    fast_io();

    // single test case:
    // solve();

    // multiple test cases:
    int t; cin >> t; while(t--) solve();

    return 0;
}