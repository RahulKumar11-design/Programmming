#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    Node* left;
    Node* right;
    int h;
    int val;

    Node(int data){
        val = data;
        h = 1;
        
        left = right = nullptr;
    }
};

class AVLtree{
    Node* root;
    
public:
    AVLtree(){
        root = nullptr;
    }

    void insert(int data){
        if(root==nullptr){
            root = new Node(data);
            return;
        }

        root = searchAndBalance(root,data);
    }

    void print(){
        inorder(root);

        cout << endl << height(root) << endl;
    }

private:
    Node* searchAndBalance(Node* curr,int data){
        if(curr==nullptr){
            return new Node(data);
        }

        if(curr->val>data){
            curr->left = searchAndBalance(curr->left,data);
        }else{ 
            curr->right = searchAndBalance(curr->right,data);
        }

        heightUpdation(curr);

        //check imbalance condn
        int lh = height(curr->left);
        int rh = height(curr->right);
        Node* z = curr;
        
        if(lh-rh==2){//l
            Node* y = z->left;
            int lh2 = height(y->left);
            int rh2 = height(y->right);

            if(lh2-rh2==-1){//lr
                Node* x = y->right;
                leftRotation(y);
                z->left = x;

                rightRotation(z);
                return x;
            }else{          //ll
                rightRotation(z);
                return y;
            }
            
        }else if(lh-rh==-2){//r
            Node* y = z->right;
            int lh2 = height(y->left);
            int rh2 = height(y->right);

            if(lh2-rh2==1){//rl
                Node* x = y->left;
                rightRotation(y);
                z->right = x;

                leftRotation(z);
                return x;
            }else{          //rr
                leftRotation(z);
                return y;
            }

        }

        return curr;
    }

    void heightUpdation(Node* z){
        z->h = max(height(z->left),height(z->right))+1;
    }

    void leftRotation(Node* z){
        Node* y = z->right;
        z->right = y->left;
        y->left = z;

        heightUpdation(z);
        heightUpdation(y);
    }

    void rightRotation(Node* z){
        Node* y = z->left;
        z->left = y->right;
        y->right = z;

        heightUpdation(z);
        heightUpdation(y);
    }

    void inorder(Node* curr){
        if(curr==nullptr){
            return;
        }
        inorder(curr->left);
        cout << curr->val << " ";
        inorder(curr->right);
    }

    int height(Node* node){
        if(node==nullptr){
            return 0;
        }else{
            return node->h;
        }
    }
};

int max(int a,int b){
    if(a>=b) return a;
    else return b;
}

int main(){
    AVLtree tree;

    for(int i=6;i<=100;i++){
        tree.insert(i);
    }

    tree.print();
    

    return 0;
}