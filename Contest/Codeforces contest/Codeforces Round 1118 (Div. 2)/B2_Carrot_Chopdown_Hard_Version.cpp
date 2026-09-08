#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <cmath>
#include <numeric>
#include <iomanip>
using namespace std;

#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

const int MOD = 1e9 + 7;
const ll INF = 1e18;
const int N = 2e5 + 5;

ll pref[N];

void solve() {
    // Your code here
    ll n,m;
    cin >> n >> m;

    for(int i=0;i<=m;i++){
        pref[i]=0;
    }

    vector<ll> ans(m+1);
    ll sum = 0;
    
    //count freq
    for(int i=0;i<n;i++){
        int ai;
        cin >> ai;
        sum+=ai;

        pref[ai]++;
    }
    //cal prefix sum
    for(int i=1;i<=m;i++){
        pref[i]+=pref[i-1];
    }

    for(int k=1;k<=min(17ll,m);k++){
        ll maxi=0;
        ll p = 1ll<<(k);
        for(int c=1;c<=m;c++){
            ll carrots = 0;
            //l<2^k *c
            ll l,atmost_carrots = p*c;
            for(l=2*c-1;l<min(atmost_carrots,m);l+=c){
                carrots+=(pref[l]-pref[l-c])*(l/c);
            }
            if(m<atmost_carrots){
                carrots+=(pref[m]-pref[l-c])*(m/c);
            }

            //l==2^k *c
            if(m>=atmost_carrots){
                carrots+=(pref[atmost_carrots]-pref[atmost_carrots-1])*p;
            }
            //l>2^k *c
            if(m>atmost_carrots){
                carrots+=(pref[m]-pref[atmost_carrots])*(p-1);
            }

            maxi = max(maxi,carrots);
        }
        ans[k] = maxi;
    }

    for(int k=18;k<=m;k++){
        ans[k] = sum;
    }

    for(int k=1;k<=m;k++){
        cout << ans[k] << " ";
    }

    cout << endl;
    
}

int32_t main() {
    fast_io();

    // single test case:
    // solve();

    // multiple test cases:
    int t; cin >> t; while(t--) solve();

    return 0;
}
