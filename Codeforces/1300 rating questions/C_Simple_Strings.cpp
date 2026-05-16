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
    string s;
    cin >> s;
    int n = s.length();

    string ans = "";

    int op = 0;
    int i=0;
    while(i<n){
        if(i+1<n && s[i]==s[i+1]){
            ans+=s[i];
            if(s[i]!='a' && (i+2>=n || s[i+2]!='a')){
                ans+='a';
            }else if(s[i]!='b' && (i+2>=n || s[i+2]!='b')){
                ans+='b';
            }else{
                ans+='c';
            }

            i+=2;
        }else{
            ans+=s[i];
            i++;
        }
    }

    cout << ans << endl;
}

int32_t main() {
    fast_io();

    solve();

    // int t;
    // cin >> t;
    // while (t--) solve();

    return 0;
}