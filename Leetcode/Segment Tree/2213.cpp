#include<bits/stdc++.h>
using namespace std;

class Solution {
    struct Node{
        int maxlen;
        int pre;
        int suff;
        char leftChar;
        char rightChar;

        Node(){
            maxlen = pre = suff = 0;
            leftChar = rightChar = 'a';
        }
    };
    struct SegmentTree{
        vector<Node> tree;

        SegmentTree(string &s){
            int n = s.length();

            tree.resize(4*n);

            build(0,0,n-1,s);
        }

        void build(int i,int st,int end,string &s){
            if(st==end){
                tree[i].leftChar = tree[i].rightChar = s[st];
                tree[i].maxlen = tree[i].pre = tree[i].suff  = 1;

                return;
            }
            int mid = st+(end-st)/2;

            build(2*i+1,st,mid,s);
            build(2*i+2,mid+1,end,s);

            tree[i] = merge(tree[2*i+1],tree[2*i+2],mid-st+1,end-mid);
        }

        Node merge(Node& left,Node& right,int leftlen,int rightlen){
            Node root;
            root.leftChar = left.leftChar;
            root.rightChar = right.rightChar;

            root.maxlen = max(left.maxlen,right.maxlen);

            if(left.rightChar==right.leftChar){
                int len = left.suff + right.pre;

                root.maxlen = max(root.maxlen,len);
            }

            root.pre = left.pre;

            if(left.rightChar==right.leftChar && left.pre==leftlen){
                root.pre = left.pre+right.pre;
            }

            root.suff = right.suff;

            if(left.rightChar==right.leftChar && right.suff==rightlen){
                root.suff = left.suff+right.suff;
            }

            return root;
        }

        int query(){
            return tree[0].maxlen;
        }

        void update(int i,int st,int end,int pos,char c){
            if(st==end){
                tree[i].leftChar = tree[i].rightChar = c;
                return;
            }

            int mid = st+(end-st)/2;

            if(pos<=mid){
                update(2*i+1,st,mid,pos,c);
            }else{
                update(2*i+2,mid+1,end,pos,c);
            }

            tree[i] = merge(tree[2*i+1],tree[2*i+2],mid-st+1,end-mid);
        }
    };
public:
    vector<int> longestRepeating(string s, string qChar, vector<int>& qInd) {
        int n,k;
        n = s.length();
        k = qInd.size();
        vector<int> ans(k);

        SegmentTree st(s);

        for(int i=0;i<k;i++){
            //update
            s[qInd[i]] = qChar[i];
            st.update(0,0,n-1,qInd[i],qChar[i]);

            //maxlen
            ans[i] = st.query();
        }

        return ans;
    }
};