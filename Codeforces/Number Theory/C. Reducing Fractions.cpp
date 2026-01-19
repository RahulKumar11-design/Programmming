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

const ll MOD = 1e9 + 7;
const ll INF = 1e18;

const int N = 1e7+1;

int spf[N];

void sieve(){
    for(int i=2;i<N;i++) spf[i]=i;

    for(int i=2;i*i<N;i++){
        if(spf[i]==i){
            for(int j=i*i;j<N;j+=i){
                spf[j]=min(spf[j],i);
            }
        }
    }
}

int binaryExp(int a,int b){
    int ans=1;

    while(b){
        if(b&1){
            ans*=a;
        }
        a*=a;
        b>>=1;
    }

    return ans;
}

void solve() {
    // Your code here
    int n,m;
    cin >> n >> m;
    vector<int> a(n),b(m);
    unordered_map<int,int> p1,p2,p3;
    sieve();

    for(int i=0;i<n;i++){
        int ai;cin >> ai;
        a[i]=ai;
        //prime factorisation
        while(ai>1){
            int p=spf[ai],cnt=0;

            while(ai%p==0){
                ai/=p;cnt++;
            }

            p1[p]+=cnt;
        }
    }

    for(int i=0;i<m;i++){
        int bi;cin >> bi;
        b[i]=bi;
        //prime factorisation
        while(bi>1){
            int p=spf[bi],cnt=0;

            while(bi%p==0){
                bi/=p;cnt++;
            }

            p2[p]+=cnt;
        }
    }

    for(auto&[key,freq]:p1){
        if(p2.count(key))
            p3[key] = min(freq,p2[key]);
    }

    p1 = p2 = p3;

    for(int i=0;i<n;i++){
        int x = a[i];
        while(x>1){
            int cnt = 0;
            int p = spf[x];
            while(x%p==0){
                cnt++;x/=p;
            }

            cnt = min(cnt,p1[p]);
            p1[p]-=cnt;
            for(int k=0;k<cnt;k++) a[i] /= p;
        }
    }

    for(int i=0;i<m;i++){
        int x = b[i];
        
        while(x>1){
            int cnt = 0;
            int p = spf[x];
            while(x%p==0){
                cnt++;x/=p;
            }

            cnt = min(cnt,p2[p]);
            p2[p]-=cnt;
            for(int k=0;k<cnt;k++) b[i] /= p;
        }
    }

    cout << n << " " << m << endl;

    for(int i=0;i<n;i++) cout << a[i] << " ";
    cout << endl;
    for(int i=0;i<m;i++) cout << b[i] << " ";
}

int32_t main() {
    fast_io();

    // single test case:
    solve();

    // multiple test cases:
    // int t; cin >> t; while(t--) solve();

    return 0;
}