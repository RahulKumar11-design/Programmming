#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

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

    vector<int> a(n+1,0);
    for(int i=1;i<=n;++i){
        cin >> a[i];
    }

    while(n>5){
        int wdw;
        for(int i=31;i>=0;i--){
            if((n&(1<<i))){
                wdw = 1<<i;
                break;
            }
        }
        for(int i=1;i<=n;++i){
            a[i]^=a[i-1];
        }
        int n_n = n-wdw+1;
        vector<int> n_arr(n_n+1,0);

        for(int i=1;i<=n_n;i++){
            n_arr[i] = a[i+wdw-1]^a[i-1];
        }

        a = n_arr;
        n = n_n;
    }

    if(n==1){
        cout << a[1] << endl;
    }else if(n==2){
        cout << (a[1]^a[2]) << endl;
    }else if(n==3){
        cout << (a[1]^a[3]) << endl;
    }else if(n==4){
        cout << (a[1]^a[2]^a[3]^a[4]) << endl;
    }else{
        cout << (a[1]^a[5]) << endl;
    }
}

int32_t main() {
    fast_io();

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}