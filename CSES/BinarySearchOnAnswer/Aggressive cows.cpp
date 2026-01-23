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

bool fn(vector<int>& stalls,int cows,int dist){
    int placed = 1;int prev = stalls[0];

    for(int i=1;i<stalls.size();i++){
        if(stalls[i]-prev>=dist){
            placed++;
            prev=stalls[i];
        }

        if(placed==cows){
            return true;
        }
    }

    return false;
}

void solve() {
    // Your code here
    int n,c;
    cin >> n >> c;
    vector<int> stalls(n);
    for(int i=0;i<n;i++){
        cin >> stalls[i];
    }
    sort(all(stalls));

    int low=0,high=1e9,ans=0;

    while(low<=high){
        int mid = low+(high-low)/2;

        if(fn(stalls,c,mid)){
            ans = max(ans,mid);
            low = mid+1;
        }else{
            high = mid-1;
        }
    }

    cout << ans << "\n";
}

int32_t main() {
    fast_io();

    // single test case:
    // solve();

    // multiple test cases:
    int t; cin >> t; while(t--) solve();

    return 0;
}