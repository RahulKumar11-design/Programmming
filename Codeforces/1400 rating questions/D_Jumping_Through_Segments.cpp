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

const int MOD = 1e9 + 7;
const ll INF = 1e18;
const int N = 2e5 + 5;

bool fn(int k,vector<pair<int,int>>& v){
    int l=-k,r=k;

    for(auto& [st,end]:v){
        if(r<st || end<l){
            return false;
        }

        if(l<=st){
            l=st;
            r = min(r,end);
        }else{
            r = min(r,end);
        }
        l-=k;
        r+=k;
    }

    return true;
}

void solve() {
    // Your code here
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);

    for(int i=0;i<n;i++){
        cin >> v[i].first >> v[i].second;
    }
    
    int low = 0,high = 1e9,ans=0;

    while(low<=high){
        int mid = low+(high-low)/2;

        if(fn(mid,v)){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }

    cout << ans << endl;
}

int32_t main() {
    fast_io();

    // single test case:
    // solve();

    // multiple test cases:
    int t; cin >> t; while(t--) solve();

    return 0;
}
