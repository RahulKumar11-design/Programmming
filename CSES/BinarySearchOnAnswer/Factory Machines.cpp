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
const ll N = 2e5 + 5;

bool predicatefn(vector<int>& mac,int req_pdts,ll time){
    ll pdts=0;

    for(int i=0;i<mac.size();i++){
        pdts+=time/mac[i];

        if(pdts>=req_pdts){
            return true;
        }
    }

    return false;
}

void solve() {
    // Your code here
    int n,pdt;
    cin >> n >> pdt;
    vector<int> mac(n);
    for(int i=0;i<n;i++) cin >> mac[i];

    ll low=1,high=1e18,ans;

    while(low<=high){
        ll mid = low+(high-low)/2;

        if(predicatefn(mac,pdt,mid)){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    
    cout << ans << "\n";
}

int32_t main() {
    fast_io();

    // single test case:
    solve();

    // multiple test cases:
    // int t; cin >> t; while(t--) solve();

    return 0;
}