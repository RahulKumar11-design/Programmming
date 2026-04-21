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

    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            int wdw = 1;
            while(i<n-1 && s[i]==s[i+1]){
                i++;wdw++;
            }

            if(wdw>3){
                no;
                return;
            }
        }
    }

    int ct=0;

    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            ct++;
            if(i<n-2 && s[i+1]==s[i+2]){
                i++;
            }else{
                while(i<n-2 && s[i+1]!=s[i+2]){
                    i++;
                }
                i++;
            }
        }

        if(ct>1){
            no;
            return;
        }
    }

    yes;
}

int32_t main() {
    fast_io();

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}