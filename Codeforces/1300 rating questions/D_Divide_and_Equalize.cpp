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
const int N = 1e6+1;
int spf[N];
void solve() {
    int n;
    cin >> n;

    vi a(n);
    for(int i=0;i<n;++i) cin >> a[i];

    map<int,int> mp;

    for(auto& it:a){
        if(it>1){
            while(it>1){
                int p = spf[it];
                while(it%p==0){
                    mp[p]++;
                    it/=p;
                }
            }
        }
    }

    for(auto &[p,freq]:mp){
        if(freq%n!=0){
            no;
            return;
        }
    }

    yes;
}

void seive(){
    spf[0] = spf[1] = -1;
    for(int i=2;i<N;i++) spf[i]=i;

    for(int i=2;i*i<N;i++){
        if(spf[i]==i){
            for(int j=i*i;j<N;j+=i){
                spf[j] = min(spf[i],i);
            }
        }
    }
}

int32_t main() {
    fast_io();

    int t;
    cin >> t;
    seive();
    while (t--) solve();

    return 0;
}