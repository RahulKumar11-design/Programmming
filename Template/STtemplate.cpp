#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;

    Node(int v = 0) {
        val = v;
    }

    void merge(const Node &left, const Node &right) {
        val = left.val + right.val;   // Change according to problem
    }
};

struct SegmentTree {
    int n;
    vector<Node> tree;

    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n + 4);
    }

    void build(int idx, int l, int r, vector<int> &arr) {
        if (l == r) {
            tree[idx] = Node(arr[l]);
            return;
        }

        int mid = (l + r) / 2;

        build(2 * idx, l, mid, arr);
        build(2 * idx + 1, mid + 1, r, arr);

        tree[idx].merge(tree[2 * idx], tree[2 * idx + 1]);
    }

    void update(int idx, int l, int r, int pos, int val) {
        if (l == r) {
            tree[idx] = Node(val);
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(2 * idx, l, mid, pos, val);
        else
            update(2 * idx + 1, mid + 1, r, pos, val);

        tree[idx].merge(tree[2 * idx], tree[2 * idx + 1]);
    }

    Node query(int idx, int l, int r, int ql, int qr) {
        // No overlap
        if (r < ql || l > qr)
            return Node(0);

        // Complete overlap
        if (ql <= l && r <= qr)
            return tree[idx];

        int mid = (l + r) / 2;

        Node left = query(2 * idx, l, mid, ql, qr);
        Node right = query(2 * idx + 1, mid + 1, r, ql, qr);

        Node ans;
        ans.merge(left, right);
        return ans;
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();

    SegmentTree st(n);

    st.build(1, 0, n - 1, arr);

    cout << st.query(1, 0, n - 1, 1, 3).val << "\n";   // 2+3+4 = 9

    st.update(1, 0, n - 1, 2, 10);                     // arr[2] = 10

    cout << st.query(1, 0, n - 1, 1, 3).val << "\n";   // 2+10+4 = 16
}