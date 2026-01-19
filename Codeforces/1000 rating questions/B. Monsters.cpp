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
const int INF = 1e18;
const int N = 2e5 + 5;

void solve() {
    // Your code here
    int n,k;
    cin >> n >> k;

    vector<pair<int,int>> arr(n);

    for(int i=0;i<n;i++){
        cin >> arr[i].first;
        arr[i].second = i+1;
    }

    for(int i=0;i<n;i++){
        arr[i].first%=k;

        if(arr[i].first==0){
            arr[i].first = k;
        }
    }

    auto cmp = [](auto& a,auto& b){
        if(a.first==b.first){
            return a.second<b.second;
        }
        return a.first>b.first;
    };
    sort(arr.begin(),arr.end(),cmp);

    for(int i=0;i<n;i++){
        cout << arr[i].second << " ";
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