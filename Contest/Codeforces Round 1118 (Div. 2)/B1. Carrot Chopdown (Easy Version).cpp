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

using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

const int INF = 1e18;
const int MOD = 1e9 + 7;

// ---------- Solve ----------

int pref[200005];

void solve() {
    int n,m;
    cin >> n >> m;

    for(int i=0;i<=m;i++){
        pref[i]=0;
    }

    vector<int> a(n);

    for(int i=0;i<n;i++){
        cin >> a[i];

        pref[a[i]]++;
    }

    for(int i=1;i<=m;i++){
        pref[i]+=pref[i-1];
    }

    int maxi = n;

    for(int ai:a){
        if(ai%2==0){
            int freq = pref[ai]-pref[ai-1];

            int tot_f = freq + pref[m]-pref[ai/2 -1];

            maxi = max(maxi,tot_f);
        }
    }

    cout << maxi << endl;

}

// ---------- Main ----------

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 1;
    cin >> tc;

    while (tc--) {
        solve();
    }

    return 0;
}