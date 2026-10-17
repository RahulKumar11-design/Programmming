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

bool match(string s,string t){
    if((int)s.length()!=(int)t.length()){
        return false;
    }
    
    int ct=0;

    for(int i=0;i<(int)s.length();i++){
        if(s[i]!=t[i]){
            ct++;
        }

        if(ct>1){
            return false;
        }
    }

    return true;
}

void solve() {
    // Your code here
    int n,m;
    cin >> n >> m;

    vector<string> s(n),t(m);

    for (int i = 0; i < n; i++){
        cin >> s[i];
    }

    for (int i = 0; i < m; i++){
        cin >> t[i];
    }

    vector<int> votes(n,0);

    for(int j=0;j<m;j++){
        int idx=-1,ct=0;
        bool same = false;

        for(int i=0;i<n;i++){
            if(s[i]==t[j]){
                votes[i]++;
                same = true;
                break;
            }

            if(match(s[i],t[j])){
                idx=i;ct++;
            }
        }

        if(!same && ct==1){
            votes[idx]++;
        }
    }

    for(int i=0;i<n;i++){
        cout << votes[i] << "\n";
    }

    
}

int32_t main() {
    fast_io();

    // single test case:
    solve();

    // // multiple test cases:
    // int t;
    // cin >> t;
    // while (t--) solve();

    return 0;
}