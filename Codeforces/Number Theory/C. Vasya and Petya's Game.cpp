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

bool prime_its_powers(int x){

    for(int div=2;div*div<=x;div++){
        if(x%div==0){
            while(x%div==0) x/=div;

            if(x!=1){
                return false;
            }
        }
    }

    return true;
}

void solve() {
    // Your code here
    int n;
    cin >> n;

    vector<int> seq;

    for(int i=2;i<=n;i++){
        if(prime_its_powers(i)){
            seq.push_back(i);
        }
    }

    cout << seq.size() << "\n";

    for(int num:seq){
        cout << num << " ";
    }
}

int32_t main() {
    fast_io();

    // single test case:
    solve();

    // multiple test cases:
    // int t; cin >> t; while(t--) solve();

    return 0;
}