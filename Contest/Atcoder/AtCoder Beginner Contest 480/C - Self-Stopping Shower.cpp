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
    int n,k,t;
    cin >> n >> k >> t;

    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(),a.end());//edge case

    int press = 0;

    if(a[0]>t){
        press+=(t+k-1)/k;
    }else{
        press+=(a[0]+k-1)/k;
    }

    for(int i=1;i<n;i++){
        if(a[i]>t){
            if(t-a[i-1]>k){
                press+=(t-a[i-1]-1)/k;
            }
            break;
        }
        if(a[i]-a[i-1]>k){
            press+=(a[i]-a[i-1]-1)/k;
        }
    }
    
    if(t-a[n-1]>k){
        press+=(t-a[n-1]-1)/k;
    }

    cout << press;
    
}

int32_t main() {
    fast_io();

    // single test case:
    solve();

    // multiple test cases:
    // int t;
    // cin >> t;
    // while (t--) solve();

    return 0;
}