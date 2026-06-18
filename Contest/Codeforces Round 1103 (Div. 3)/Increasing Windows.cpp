#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

const int MAXN = 400005; 
const int MOD = 998244353;

ll fact[MAXN], invFact[MAXN];

ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) fact[i] = (fact[i - 1] * i) % MOD;
    invFact[MAXN - 1] = power(fact[MAXN - 1], MOD - 2);
    for (int i = MAXN - 2; i >= 0; i--) invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
}

ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
}

void solve() {
    int n, k;
    cin >> n >> k;

    ll ans = 0;
    // v is the value of A_{K+1}. 
    // It must be at least 1, and there must be at least (N-K-1) values above it.
    // Also, (v-1) must be at least 1 if we want (v-1)^k to be non-zero, so v starts at 2.
    for (int v = 2; v <= n; v++) {
        ll choices_for_head = power(v - 1, k);
        ll choices_for_tail = nCr(n - v, n - (k + 1)); 
        
        ll term = (choices_for_head * choices_for_tail) % MOD;
        ans = (ans + term) % MOD;
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}