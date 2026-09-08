#include <bits/stdc++.h>
using namespace std;

bool lex_smaller(
    vector<int>& A,
    vector<int>& B,
    unordered_set<int>& used)
{
    int i = 0, j = 0;

    while (true) {
        while (i < A.size() && used.count(A[i])) i++;
        while (j < B.size() && used.count(B[j])) j++;

        if (i == A.size() && j == B.size()) return false;
        if (i == A.size()) return true;
        if (j == B.size()) return false;

        if (A[i] != B[j])
            return A[i] < B[j];

        i++; j++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> blogs(n);
        unordered_set<int> all_users;

        for (int i = 0; i < n; i++) {
            int l; cin >> l;
            blogs[i].resize(l);
            for (int j = 0; j < l; j++) {
                cin >> blogs[i][j];
                all_users.insert(blogs[i][j]);
            }
        }

        // build reversed unique
        vector<vector<int>> rev_unique(n);
        for (int i = 0; i < n; i++) {
            unordered_set<int> seen;
            for (int j = blogs[i].size()-1; j >= 0; j--) {
                if (!seen.count(blogs[i][j])) {
                    seen.insert(blogs[i][j]);
                    rev_unique[i].push_back(blogs[i][j]);
                }
            }
        }

        unordered_set<int> used;
        vector<bool> taken(n,false);
        vector<int> Q;

        int total = all_users.size();

        while (Q.size() < total) {

            int best = -1;

            for (int i = 0; i < n; i++) {
                if (taken[i]) continue;

                if (best == -1 ||
                    lex_smaller(rev_unique[i],
                                rev_unique[best],
                                used))
                    best = i;
            }

            taken[best] = true;

            for (int u : rev_unique[best]) {
                if (!used.count(u)) {
                    used.insert(u);
                    Q.push_back(u);
                }
            }
        }

        for (int i = 0; i < Q.size(); i++) {
            cout << Q[i] << " ";
        }
        cout << '\n';
    }
}