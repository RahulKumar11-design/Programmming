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
    int n;
    cin >> n;

    vector<int> a(n),b(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
    }

    unordered_map<int,int> mp;
    int maxi=1,ele=a[0],freq=1;

    for(int i=1;i<n;i++){
        if(ele!=a[i]){
            mp[ele]+=0;
            mp[ele]=max(freq,mp[ele]);
            maxi = max(maxi,freq);
            ele = a[i];
            freq=1;
        }else{
            freq++;
        }
    }
    mp[ele]+=0;
    mp[ele]=max(freq,mp[ele]);
    maxi = max(maxi,freq);

    ele=b[0],freq=1;

    for(int i=1;i<n;i++){
        if(ele!=b[i]){
            int occ = freq;
            if(mp.count(ele)!=0){
                occ += mp[ele];
            }
            maxi = max(maxi,occ);
            ele = b[i];
            freq=1;
        }else{
            freq++;
        }
    }
    int occ = freq;
    if(mp.count(ele)!=0){
        occ += mp[ele];
    }
    maxi = max(maxi,occ);

    cout << maxi << endl;
}

int32_t main() {
    fast_io();

    // single test case:
    // solve();

    // multiple test cases:
    int t; cin >> t; while(t--) solve();

    return 0;
}