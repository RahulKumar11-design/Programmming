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
    char c;
    cin >> n >> c;
    string s;
    cin >> s;
    if(c=='g'){
        cout << "0\n";
        return;
    }
    bool flag = false;
    int maxlen=0,len=0;

    for(int i=0;i<n;i++){
        if(flag){
            if(s[i]=='g'){
                maxlen = max(maxlen,len);
                flag = false;
                len=0;
            }else{
                len++;
            }
        }else{
            if(s[i]==c){
                flag=true;
                len++;
            }
        }
    }

    if(flag){
        for(int i=0;i<n;i++){
            if(s[i]=='g'){
                maxlen = max(maxlen,len);
                break;
            }else{
                len++;
            }
        }
    }

    cout << maxlen << endl;
}

int32_t main() {
    fast_io();

    // single test case:
    // solve();

    // multiple test cases:
    int t; cin >> t; while(t--) solve();

    return 0;
}