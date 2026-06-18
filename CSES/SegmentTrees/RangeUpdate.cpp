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

class SegmentTree{
public:
    vector<ll> tree;//store how much increased

    SegmentTree(int n){
        tree.resize(4*n);
    }

    void update(int i,int st,int end,int l,int r,int val){
        if(tree[i]!=0 && st!=end){
            //do pending work
            tree[2*i+1]+=tree[i];
            tree[2*i+2]+=tree[i];
            tree[i]=0;
        }

        if(r<st || end<l) return;

        if(l<=st && end<=r){
            //be lazy
            tree[i] += val;
            return;
        }

        int mid = st+(end-st)/2;
        update(2*i+1,st,mid,l,r,val);
        update(2*i+2,mid+1,end,l,r,val);
    }

    ll getAdditions(int i,int st,int end,int k){
        if(st==end){
            return tree[i];
        }

        if(tree[i]!=0){
            //do pending work
            tree[2*i+1]+=tree[i];
            tree[2*i+2]+=tree[i];
            tree[i]=0;
        }

        int mid = st+(end-st)/2;

        if(k<=mid){
            return getAdditions(2*i+1,st,mid,k);
        }else{
            return getAdditions(2*i+2,mid+1,end,k);
        }
    }
};

void solve() {
    int n,q;
    cin >> n >> q;

    vi a(n);
    for(int i=0;i<n;++i) cin >> a[i];

    SegmentTree seg(n);

    while(q--){
        int type;
        cin >> type;
        if(type==1){
            int l,r,u;
            cin >> l >> r >> u;

            seg.update(0,0,n-1,l-1,r-1,u);
        }else{
            int k;
            cin >> k;

            cout << a[k-1]+seg.getAdditions(0,0,n-1,k-1) << endl;
        }
    }
}

int32_t main() {
    fast_io();

    solve();

    // int t;
    // cin >> t;
    // while (t--) solve();

    return 0;
}