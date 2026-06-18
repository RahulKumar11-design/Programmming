#include <bits/stdc++.h>
using namespace std;

struct Node {
    int ones;
    int ans;
};

struct SegTree {
    int n;
    vector<Node> st;
    vector<int> lazy;

    SegTree(int n) : n(n) {
        st.resize(4 * n + 5);
        lazy.assign(4 * n + 5, -1);
        build(1, 1, n);
    }

    Node mergeNode(const Node &a, const Node &b) {
        Node res;

        res.ones = a.ones + b.ones;

        int rightAns = -1;
        if (b.ans != -1)
            rightAns = a.ones + b.ans;

        res.ans = max(a.ans, rightAns);

        return res;
    }

    void build(int p, int l, int r) {
        if (l == r) {
            // Initially all zeros
            st[p] = {0, 0};
            return;
        }

        int m = (l + r) >> 1;

        build(p << 1, l, m);
        build(p << 1 | 1, m + 1, r);

        st[p] = mergeNode(st[p << 1], st[p << 1 | 1]);
    }

    void apply(int p, int l, int r, int val) {
        lazy[p] = val;

        if (val == 0) {
            st[p].ones = 0;
            st[p].ans = 0;
        } else {
            st[p].ones = r - l + 1;
            st[p].ans = -1;
        }
    }

    void push(int p, int l, int r) {
        if (lazy[p] == -1 || l == r) return;

        int m = (l + r) >> 1;

        apply(p << 1, l, m, lazy[p]);
        apply(p << 1 | 1, m + 1, r, lazy[p]);

        lazy[p] = -1;
    }

    void update(int p, int l, int r,
                int ql, int qr, int val) {

        if (ql > r || qr < l) return;

        if (ql <= l && r <= qr) {
            apply(p, l, r, val);
            return;
        }

        push(p, l, r);

        int m = (l + r) >> 1;

        update(p << 1, l, m, ql, qr, val);
        update(p << 1 | 1, m + 1, r, ql, qr, val);

        st[p] = mergeNode(st[p << 1], st[p << 1 | 1]);
    }

    void update(int l, int r, int val) {
        if (l > r) return;
        update(1, 1, n, l, r, val);
    }

    int totalOnes() {
        return st[1].ones;
    }

    int answer() {
        if (st[1].ans == -1)
            return 1;

        return st[1].ans + 1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, Q;
        cin >> N >> Q;

        SegTree seg(N);

        while (Q--) {
            int type;
            cin >> type;

            if (type == 0 || type == 1) {
                int L, R;
                cin >> L >> R;

                seg.update(L, R, type);
            }
            else {
                int ones = seg.totalOnes();
                int zeros = N - ones;

                if (zeros)
                    seg.update(1, zeros, 0);

                if (ones)
                    seg.update(zeros + 1, N, 1);
            }

            cout << seg.answer() << '\n';
        }
    }

    return 0;
}