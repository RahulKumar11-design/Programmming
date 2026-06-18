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

class SegTree{
public:
    vector<int> tree;

    SegTree(vector<int>& arr){
        int n = arr.size();
        tree.resize(4*n);

        buildTree(arr,0,0,n-1);
    }

    void buildTree(vector<int>& arr,int i,int st,int end){
        if(st==end){
            tree[i] = arr[st];
            return;
        }

        int mid = st + (end-st)/2;

        buildTree(arr,2*i+1,st,mid);
        buildTree(arr,2*i+2,mid+1,end);

        tree[i] = tree[2*i+1]+tree[2*i+2];
    }

    void update(int i,int st,int end,int idx,int val){
        if(st==idx && end==idx){
            tree[i] = val;
            return;
        }else if(idx<st || end<idx){
            return;
        }

        int mid = st + (end-st)/2;

        update(2*i+1,st,mid,idx,val);
        update(2*i+2,mid+1,end,idx,val);

        tree[i] = tree[2*i+1]+tree[2*i+2];
    }

    int range_query(int i,int st,int end,int qi,int qj){
        if(qj<st || end<qi){//no overlapping
            return 0;
        }else if(qi<=st && end<=qj){// full overlapping
            return tree[i];
        }
        //partial overlapping
        int mid = st + (end-st)/2;
        return range_query(2*i+1,st,mid,qi,qj)+range_query(2*i+2,mid+1,end,qi,qj);
    }
};

void solve() {
    int n;
    cin >> n;

    vi a(n);
    for(int i=0;i<n;++i) cin >> a[i];
}

int32_t main() {
    fast_io();

    //solve();

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}