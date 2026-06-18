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
    int n,k;
    cin >> n >> k;

    vll a(n);
    for(int i=0;i<n;++i) cin >> a[i];

    if(k>=3){
        cout << "0\n";
        return;
    }

    sort(all(a));

    if(k==1){
        ll mini = a[0];

        for(int i=1;i<n;i++){
            mini = min(mini,a[i]);

            ll diff = a[i]-a[i-1];

            mini = min(mini,diff);
        }

        cout << mini << "\n";
    }else{
        ll mini = a[0];
        for(int i=0;i<n-1;i++){
            mini = min(mini,a[i+1]);
            for(int j=i+1;j<n;j++){
                ll diff = a[j]-a[i];
                mini = min(mini,diff);

                int low=0,high=n-1,ans=0;

                while(low<=high){
                    int mid = low + (high-low)/2;

                    if(a[mid]<=diff){
                        low = mid+1;
                        ans = mid;
                    }else{
                        high = mid-1;
                    }
                }
                ll diff2 = abs(a[ans]-diff);
                mini = min(mini,diff2);
                if(ans+1<n){
                    diff2 = abs(a[ans+1]-diff);
                    mini = min(mini,diff2);
                }
            }
        }

        cout << mini << "\n";
    }
}

int32_t main() {
    fast_io();

    //solve();

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}