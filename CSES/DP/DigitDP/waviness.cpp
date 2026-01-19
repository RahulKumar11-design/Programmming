#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// dp[tight][leading][pos][prev1][prev2]
ll dp[2][2][20][11][11];
string s;

// returns total waviness over all numbers from this state
ll go(int pos, int prev1, int prev2, bool tight, bool leading) {
    if (pos == s.size()) return 0;

    ll &res = dp[tight][leading][pos][prev1][prev2];
    if (res != -1) return res;

    int limit = tight ? (s[pos] - '0') : 9;
    ll ans = 0;

    for (int dig = 0; dig <= limit; dig++) {
        bool ntight = tight && (dig == limit);
        bool nleading = leading && (dig == 0);

        ll wave = 0;
        int np1, np2;

        if (nleading) {
            // still leading zeros → no valid digits yet
            np1 = 10;
            np2 = 10;
        } 
        else {
            // shift prevs
            np2 = prev1;
            np1 = dig;

            // check wave only if both prev2 and prev1 exist
            if (prev2 != 10 && prev1 != 10) {
                if ((prev2 < prev1 && prev1 > dig) ||
                    (prev2 > prev1 && prev1 < dig))
                    wave = 1;
            }
        }

        ans += wave + go(pos + 1, np1, np2, ntight, nleading);
    }

    return res = ans;
}

ll calc(ll x) {
    if (x < 0) return 0;
    s = to_string(x);
    memset(dp, -1, sizeof(dp));
    return go(0, 10, 10, true, true);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, b;
    cin >> a >> b;
    ll right = calc(b) ;
    ll left = calc(a - 1);

    cout << right << " " << left << "\n";
    cout << right-left;
    return 0;
}
