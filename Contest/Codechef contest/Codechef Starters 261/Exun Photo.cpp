#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
    int n;
    vector<int> tree;
public:
    FenwickTree(int n){
        this->n = n;
        tree.resize(n+1);
    }

    void add(int i) {
        for (; i <= n; i += i & -i)
            tree[i] += 1;
    }

    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i)
            sum += tree[i];
        return sum;
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    if (k == 1) {
        bool sorted = true;
        for (int i = 0; i < n; i++) {
            if (p[i] != n - i) {
                sorted = false;
                break;
            }
        }
        if (sorted) {
            cout << 0 << "\n";
        } else {
            cout << -1 << "\n";
        }
        return;
    }

    FenwickTree ft(n);
    long long total_ops = 0;

    for (int i = 0; i < n; i++) {
        int smaller_before = ft.query(p[i]-1);
        ft.add(p[i]);
        
        if(smaller_before==0) continue;
        
        int no_of_intervals = (smaller_before+k)/k;
        total_ops+=no_intervals;
    }

    cout << total_ops << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}