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
const int N = 1e5;

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
    int n,m;
    cin >> n >> m;

    sieve();
    vector<int> primes(n+1,0);//prime - idx
    bool activated1 = false;

    for(int q=0;q<m;q++){
        char op;cin >> op;
        int idx;cin >> idx;

        //prime factorisation
        if(op=='+'){
            if(idx==1){
                if(activated1){
                    cout << "Already on\n";
                }else{
                    activated1 = true;
                    cout << "Success\n";
                }
                continue;
            }
            int num = idx;bool isSuccess = true;
            vector<int> update;

            for(int p=2;p*p<=num;p++){//o(logn)
                if(num%p==0){
                    if(primes[p]==idx){
                        cout << "Already on\n";
                        isSuccess = false;
                        break;
                    }else if(primes[p]!=0){
                        cout << "Conflict with " << primes[p] << endl;
                        isSuccess = false;
                        break;
                    }

                    //might success
                    update.push_back(p);
                }
                while(num%p==0) num/=p;
            }
            
            if(isSuccess){
                if(primes[num]==idx){
                    cout << "Already on\n";
                    continue;
                }else if(primes[num]!=0){
                    cout << "Conflict with " << primes[num] << endl;
                    continue;
                }
                if(num!=1) update.push_back(num);//primes[1]=0 always

                for(int p:update){
                    primes[p]=idx;
                }
                cout << "Success\n";
            }
        }else{
            if(idx==1){
                if(activated1){
                    cout << "Success\n";
                    activated1 = false;
                }else{
                    cout << "Already off\n";
                }
                continue;
            }

            int num = idx;bool isSuccess = true;
            for(int p=2;p*p<=num;p++){//o(logn)
                if(num%p==0){
                    if(primes[p]!=idx){
                        cout << "Already off\n";
                        isSuccess = false;
                        break;
                    }

                    //success
                    primes[p]=0;
                }
                while(num%p==0) num/=p;
            }
            if(isSuccess){
                if(num!=1 && primes[num]!=idx){
                    cout << "Already off\n";
                    continue;
                }
                primes[num]=0;//primes[1]=0 always
                cout << "Success\n";
            }
        }
    }
}

int32_t main() {
    fast_io();

    // single test case:
    solve();

    // multiple test cases:
    // int t; cin >> t; while(t--) solve();

    return 0;
}