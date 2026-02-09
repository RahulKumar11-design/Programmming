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

int spf[N+1];

void sieve(){
    for(int i=0;i<=N;i++) spf[i]=i;

    for(int i=2;i*i<=N;i++){
        if(spf[i]==i){
            for(int j=i*i;j<=N;j+=i){
                spf[j] = min(spf[j],i);
            }
        }
    }
}

void solve() {
    // Your code here
    int n;
    cin >> n;
    vector<int> a(n);

    for(int i=0;i<n;i++) cin >> a[i];

    map<int,vector<int>> mp;

    sieve();

    for(int x:a){
        while(x>1){
            int p = spf[x];
            int pow=0;
            while(x%p==0){
                pow++;
                x/=p;
            }
            mp[p].push_back(pow);
        }
    }
    ll gcd = 1;
    for(auto &[p,pwrs]:mp){
        if(sz(pwrs)>=n-1){
            sort(all(pwrs));
            int exp = (sz(pwrs)==n)?pwrs[1]:pwrs[0];
            //binary expo
            int x = p;
            while(exp>0){
                if((exp&1)){
                    gcd*=x;
                }
                x*=x;
                exp>>=1;
            }
        }
    }

    cout << gcd << "\n";
}

int32_t main() {
    fast_io();

    // single test case:
    solve();

    // multiple test cases:
    // int t; cin >> t; while(t--) solve();

    return 0;
}