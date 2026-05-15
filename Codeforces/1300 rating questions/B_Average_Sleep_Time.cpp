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
    int n, k;
    cin >> n >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long total_sum = 0;

    for (int i = 0; i < n; ++i) {
        int pos = i + 1;
        long long weight;

        if (pos < k) {
            weight = pos;
        } else if (pos > n - k + 1) {
            weight = (n - pos + 1);
        } else {
            weight = k;
        }

        total_sum += weight * a[i];
    }

    double result = (double)total_sum / (n - k + 1);

    cout << fixed << setprecision(6) << result << endl;
}

int32_t main() {
    fast_io();

    solve();

    // int t;
    // cin >> t;
    // while (t--) solve();

    return 0;
}