
#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
    int n;
    vector<long long> bit;

public:
    FenwickTree(int n) : n(n), bit(n + 1, 0) {}

    // Add delta to index i (1-based indexing)
    void update(int i, long long delta) {
        while (i <= n) {
            bit[i] += delta;
            i += (i & -i);
        }
    }

    // Sum of elements from index 1 to i
    long long prefixSum(int i) {
        long long ans = 0;
        while (i > 0) {
            ans += bit[i];
            i -= (i & -i);
        }
        return ans;
    }

    // Sum of elements from index l to r (inclusive)
    long long rangeSum(int l, int r) {
        return prefixSum(r) - prefixSum(l - 1);
    }
};

int main() {
    vector<int> a = {2, 1, 3, 4, 5};
    int n = a.size();

    FenwickTree ft(n);

    // Build the tree
    for (int i = 0; i < n; i++) {
        ft.update(i + 1, a[i]);
    }

    cout << ft.prefixSum(3) << '\n';  // 6
    cout << ft.rangeSum(2, 4) << '\n'; // 8

    ft.update(3, 7); // Add 7 to index 3

    cout << ft.prefixSum(3) << '\n';  // 13
    cout << ft.rangeSum(2, 4) << '\n'; // 15

    return 0;
}