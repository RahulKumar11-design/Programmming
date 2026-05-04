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

    queue<int> qn,q2,q3,q6;

    for(int i=0;i<n;++i){
        int ai;cin >> ai;
        if(ai%2!=0 && ai%3!=0){
            qn.push(ai);
        }else if(ai%6==0){
            q6.push(ai);
        }else{
            if(ai%3!=0){
                q2.push(ai);
            }else{
                q3.push(ai);
            }
        }
    }

    while(!q6.empty()){
        cout << q6.front() << " ";
        q6.pop();
    }

    while(!q2.empty()){
        cout << q2.front() << " ";
        q2.pop();
    }

    while(!qn.empty()){
        cout << qn.front() << " ";
        qn.pop();
    }

    while(!q3.empty()){
        cout << q3.front() << " ";
        q3.pop();
    }
    cout << endl;
}

int32_t main() {
    fast_io();

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}