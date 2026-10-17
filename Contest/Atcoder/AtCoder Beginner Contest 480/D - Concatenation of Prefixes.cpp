#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

// container & utility macros
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second

// type shortcuts
using ll = long long;
using vi = vector<int>;
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

void fast_io()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

const int MOD = 1e9 + 7;
const ll INF = 1e18;
const int N = 2e5 + 5;

void solve()
{
    // Your code here
    int n, q;
    cin >> n >> q;

    vector<ll> p(n + 1, 0), pp(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        int ai;
        cin >> ai;
        p[i] = ai + p[i - 1];

        pp[i] = p[i] + pp[i - 1];
    }

    while (q--)
    {
        ll l, r;
        cin >> l >> r;

        ll idx1 = ceil((sqrt(8 * l + 1) - 1) / 2);
        ll idx2 = ceil((sqrt(8 * r + 1) - 1) / 2);

        ll sum = pp[idx2 - 1] - pp[idx1];

        ll li = idx1 * (idx1 + 1) / 2;
        ll ri = idx2 * (idx2 + 1) / 2;

        sum += p[idx1] - p[idx1 - (li - l) - 1];
        sum += p[idx2 - (ri - r)];

        cout << sum << endl;
    }
}

int32_t main()
{
    fast_io();

    // single test case:
    solve();

    // multiple test cases:
    // int t;
    // cin >> t;
    // while (t--) solve();

    return 0;
}