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
const int N = 1e7;

bool prime[N];
bool good[N];
int prefix[N];
void sieve(){
    prime[0] = prime[1] = false;
    for(int i=2;i<N;i++){
        prime[i]=true;
    }

    for(int i=2;i*i<N;i++){
        if(!prime[i]) continue;
        for(int j=i*i;j<N;j+=i){
            prime[j] = false;
        }
    }
}

int32_t main() {
    fast_io();

    // single test case:
    // solve();

    // multiple test cases:
    sieve();

    for(int i=1;i*i<N;i++){
        for(int j=1;;j++){
            int p = i*i+j*j*j*j;

            if(p>=N) break;
            if(prime[p]) good[p]=true;
        }
    }
    prefix[0] = prefix[1] = 0;

    for(int i=2;i<N;i++){
        prefix[i] = prefix[i-1] + (good[i]?1:0);
    }

    
    int t; cin >> t; 

    while(t-->0){
        int n;cin >> n;

        cout << prefix[n] << "\n";
    }

    return 0;
}