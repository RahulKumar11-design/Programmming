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

#define int long long
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define F first
#define S second

using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

const int INF = 1e18;
const int MOD = 1e9 + 7;

// ---------- Utility ----------

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

// ---------- Solve ----------

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);

    for(int i=0;i<n;i++) cin >> v[i];

    cout << gcd(v[0],v[n-1]) << endl;
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