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
    int n;
    cin >> n;
    int m = n;

    map<int,int> mp;

    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            while(n%i==0){
                mp[i]++;
                n/=i;
            }
        }
    }

    if(n>1){
        mp[n]++;
    }

    if(mp.size()>=2){
        
        auto it = mp.begin();
        int n1 = it->first;
        it++;
        int n2 = it->first;
        if(m/(n1*n2)==n1 || m/(n1*n2)==n2){
            no;
            return;
        }

        yes;
        cout << n1 << " " << n2 << " " << m/(n1*n2) << endl;
        return;
    }

    int total=0;

    for(auto &it:mp){
        total+=it.second;
    }

    if(total>=6){
        yes;
        auto it = mp.begin(); 
        int n1 = it->first;

        cout << n1 << " " << n1*n1 << " " << m/(n1*n1*n1) << endl;  
    }else{
        no;
    }
}

int32_t main() {
    fast_io();

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}