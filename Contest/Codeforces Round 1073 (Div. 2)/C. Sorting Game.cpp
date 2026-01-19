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

    int first1=-1;
    int last0=n;

    for(int i=0;i<n;i++) {
        if(s[i]=='1' && first1==-1){
            first1=i;
        }
        if(s[n-i-1]=='0' && last0==n){
            last0=n-i-1;
        }
    }

    if(last0==n || first1==-1 || last0<first1){
        cout << "Bob\n";
        return;
    }
    vector<int> indecis;

    int l=first1,r=last0;

    while(l<r){
        if(s[l]=='1'){
            indecis.push_back(l);

            while(l<r && s[r]!='0'){
                r--;
            }
            if(l<r) indecis.push_back(r);
            r--;
        }
        l++;
    }

    sort(indecis.begin(),indecis.end());

    cout << "Alice\n";
    cout << indecis.size() << "\n";

    for(int idx:indecis) cout << idx+1 << " ";

    cout << "\n";
}

int32_t main() {
    fast_io();

    // single test case:
    // solve();

    // multiple test cases:
    int t; cin >> t; while(t--) solve();

    return 0;
}