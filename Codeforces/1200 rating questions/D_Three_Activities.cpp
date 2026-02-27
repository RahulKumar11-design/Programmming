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
    int n;
    cin >> n;

    vector<pair<int,int>> a(n),b(n),c(n);

    for(int i=0;i<n;i++){
        cin >> a[i].ff;
        a[i].ss = i+1;
    }
    for(int i=0;i<n;i++){
        cin >> b[i].ff;
        b[i].ss = i+1;
    }
    for(int i=0;i<n;i++){
        cin >> c[i].ff;
        c[i].ss = i+1;
    }
    sort(rall(a));
    sort(rall(b));
    sort(rall(c));

    int maxi = 0;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(a[i].ss!=b[j].ss && a[i].ss!=c[k].ss && b[j].ss!=c[k].ss){
                    int sum = a[i].ff+b[j].ff+c[k].ff;

                    maxi = max(maxi,sum);
                }
            }
        }
    }

    cout << maxi << endl;
}

int32_t main() {
    fast_io();

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}