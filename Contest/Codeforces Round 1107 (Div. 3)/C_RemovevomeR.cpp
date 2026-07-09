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

    string s;
    cin >> s;

    char last = s[0];
    int i = 1;
    int size = 1;

    while(i<s.length()){
        if(last!=s[i]){
            last = s[i];
            size++;
        }
        i++;
    }

    if(size==2){
        cout << "2\n";
    }else{
        cout << "1\n";
    }
}

int32_t main() {
    fast_io();

    //solve();

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}