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
    // Your code here
    int n;
    cin >> n;

    string s;
    cin >> s;

    if(n%2==1){
        cout << "-1\n";
        return;
    }
    
    vector<int> ans(n,0);
    int col = 0,bal=0;
    pair colours = {-1,-1};

    for(int i=0;i<n;i++){
        if(s[i]==')'){
            bal--;
        }else{
            bal++;
        }
        if(bal<0){
            ans[i] = 0;
            colours.first = 0;
        }else if(bal>0){
            ans[i] = 1;
            colours.second = 1;
        }else{
            ans[i] = ans[i-1];
        }
    }

    if(bal!=0){
        cout << "-1\n";
        return;
    }

    if(colours.first!=-1 && colours.second!=-1){
        cout << 2 << endl;
        for(int i=0;i<n;i++){
            cout << ans[i]+1 << " ";
        }
    }else{
        cout << 1 << endl;

        if(colours.first!=-1){
            for(int i=0;i<n;i++){
                cout << ans[i]+1 << " ";
            }
        }else{
            for(int i=0;i<n;i++){
                cout << ans[i] << " ";
            }
        }
    }

    cout << endl;
}

int32_t main() {
    fast_io();

    // single test case:
    // solve();

    // multiple test cases:
    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}