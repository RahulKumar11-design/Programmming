#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

// loop macros
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i <= (n); i++)
#define repr(i, n) for (int i = (n)-1; i >= 0; i--)
#define repab(i, a, b) for (int i = (a); i <= (b); i++)
#define repba(i, b, a) for (int i = (b); i >= (a); i--)

// container & utility macros
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second

// type shortcuts
using ll  = long long;
using vi  = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vpi = vector<pii>;

// algorithm helpers
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

// output shortcuts
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

const int MOD = 1e9 + 7;
const ll INF = 1e18;
const int N = 2e5 + 5;

void solve() {
    string st;
    cin >> st;
    int n = st.size();

    int con=0,maxi=0;
    int i;
    for(i=0;i<n;i++){
        if(st[i]=='1'){
            con++;
            if(i==n-1 && st[0]=='1' && con!=n){
                int j=0;
                while(st[j++]=='1') con++;
            }
        }else{
            con=0;
        }
        maxi = max(maxi,con);
    }

    // cout << maxi << "\n";

    if(maxi==n){
        cout << 1ll*n*n << "\n";
        return;
    }

    cout << (1ll*(maxi+1)*(maxi+1))/4 << endl; 
}

int32_t main() {
    fast_io();

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}