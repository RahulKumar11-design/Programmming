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

bool check(string &t,string &x,int i,int l,int r){
    if(i==t.length()){
        return true;
    }

    if(x[i]=='?'){
        return check(t,x,i+1,l+1,r) || check(t,x,i+1,l,r-1);
    }else{
        if(t[l]==x[i]){
            return check(t,x,i+1,l+1,r);
        }else if(t[r]==x[i]){
            return check(t,x,i+1,l,r-1);
        }else{
            return false;
        }
    }
}

void solve() {
    int n;
    cin >> n;

    string x;
    cin >> x;

    string t="";
    for(int i=1;i<=n;i++){
        if(i%2){
            t+='a';
        }else{
            t+='b';
        }
    }

    (check(t,x,0,0,n-1))?yes:no;
}

int32_t main() {
    fast_io();

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}