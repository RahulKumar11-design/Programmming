package advDS.tree;
import java.util.*;

public class BST {
    static class Node{
        int data;
        Node left;
        Node right;
        Node(int data){
            this.data=data;
        }
    }
    public static Node insert(Node root,int val){
        if(root==null){
            root= new Node(val);
            return root;
        }

        if(root.data>val){
            root.left=insert(root.left, val);
        }
        else{
            root.right=insert(root.right, val);
        }
        return root;
    }
    public static void inorder(Node root){
        if(root==null){
            return;
        }
        inorder(root.left);
        System.out.print(root.data+" ");
        inorder(root.right);
    }
    public static void preorder(Node root){
        if(root==null){
            return;
        }
        System.out.print(root.data+" ");
        preorder(root.left);
        preorder(root.right);
    }
    public static boolean search(Node root,int val){
        if(root==null){
            return false;
        }
        if(root.data==val){
            return true;
        }
        if(root.data>val){
            return search(root.left,val);
        }
        //root.data<val -> right
        return search(root.right, val);
    }
    public static Node FindInorderSuccessor(Node root){
        while(root.right!=null){
            root=root.right;
        }
        return root;
    }
    public static Node delete(Node root,int val){
        if(root.data>val){
            root.left = delete(root.left, val);
        }
        else if(root.data<val){
            root.right = delete(root.right,val);
        }
        else{
            //case1 : No child
            if(root.left==null && root.right==null){
                return null;
            }
            //case2 : one child
            if(root.right==null){
                return root.left;
            }
            if(root.left==null){
                return root.right;
            }
            //case3 : two child
            Node IS = FindInorderSuccessor(root.right);
            root.data = IS.data;
            root.right = delete(root.right,IS.data);
        }
        return root;
    }
    public static void print_range(Node root,int k1,int k2){
        if(root==null){
            return;
        }
        if(k1<=root.data && root.data<=k2){
            print_range(root.left, k1, k2);
            System.out.print(root.data+" ");
            print_range(root.right, k1, k2);
        }else if(root.data<k1){
            print_range(root.right, k1, k2);
        }else{
            print_range(root.left, k1, k2);
        }
    }
    public static void print_path(Node root,ArrayList<Integer> list){
        if(root==null){
            return;
        }
        list.add(root.data);
        if(root.left==null && root.right==null){
            System.out.println(list);
            list.remove(list.size()-1);
            return;
        }
        print_path(root.left, list);
        print_path(root.right, list);
        list.remove(list.size()-1);
    }
    public static boolean isValidBST(Node root,Node min,Node max){
        if(root==null){
            return true;
        }
        if(min!=null && root.data<=min.data){
            return false;
        }
        else if(max!=null && root.data>=max.data){
            return false;
        }
        
        return isValidBST(root.left, min, root) && isValidBST(root.right, root, max);
    }
    public static Node mirrorTree(Node root){
        if(root==null){
            return null;
        }
        Node temp = mirrorTree(root.left);
        root.left = mirrorTree(root.right);
        root.right = temp;
        return root;
    }
    public static void getInorder(Node root,ArrayList<Integer> inorder){
        if(root==null){
            return;
        }
        getInorder(root.left, inorder);
        inorder.add(root.data);
        getInorder(root.right, inorder);
    }
    public static Node createBST(ArrayList<Integer> inorder,int si,int ei){
        if(si>ei) return null;
        //mid
        int mid = si+(ei-si)/2;
        Node root = new Node(inorder.get(mid));
        root.left = createBST(inorder, si, mid-1);
        root.right = createBST(inorder, mid+1, ei);
        return root;
    }
    public static Node balanceBST(Node root){
        //inorder seq
        ArrayList<Integer> inorder = new ArrayList<>();
        getInorder(root, inorder);
        //sorted -> balance tree
        Node newroot = createBST(inorder, 0, inorder.size()-1);
        return newroot;
    }
    static class info{
        boolean isValidBST;
        int size;
        int min;
        int max;
        info(boolean isValidBST,int size,int min,int max){
            this.isValidBST = isValidBST;
            this.size = size;
            this.min = min;
            this.max = max;
        }
    }
    static int maxSize=0;
    public static info Largest_BST(Node root){
        if(root==null){
            return new info(true, 0, Integer.MAX_VALUE, Integer.MIN_VALUE);
        }
        info left = Largest_BST(root.left);
        info right = Largest_BST(root.right);
        int size = left.size+right.size+1;
        int min = Math.min(root.data,Math.min(left.min,right.min));
        int max = Math.max(root.data,Math.max(left.max,right.max));
        if(left.max>root.data || root.data>right.min || !left.isValidBST || !right.isValidBST){
            return new info(false, size, min, max);
        }
        info main = new info(true, size, min, max);
        maxSize = Math.max(maxSize,size);
        return main;
    }
    public static Node mergeBSTs(Node root1,Node root2){
        //sorted list of root1
        ArrayList<Integer> arr1 = new ArrayList<>();
        getInorder(root1, arr1);
        //sorted list of root2
        ArrayList<Integer> arr2 = new ArrayList<>();
        getInorder(root2, arr2);
         
        //merge two sorted list
        ArrayList<Integer> arr = new ArrayList<>();
        int i=0,j=0;
        while(i<arr1.size() && j<arr2.size()){
            if(arr1.get(i)<=arr2.get(j)){
                arr.add(arr1.get(i));
                i++;
            }else{
                arr.add(arr2.get(j));
                j++;
            }
        }
        while(i<arr1.size()){
            arr.add(arr1.get(i));i++;
        }
        while(j<arr2.size()){
            arr.add(arr2.get(j));j++;
        }
        //sorted arr -> balanced list
        System.out.println(arr);
        return createBST(arr,0,arr.size()-1);
    }
    static Node node;
    public static void node_minDiff(Node root,int k,int mindiff){
        if(root==null){
            return;
        }
        int diff = Math.abs(root.data-k);
        if(mindiff>diff){
            mindiff=diff;
            node=root;
        }
        node_minDiff(root.left, k, mindiff);
        node_minDiff(root.right, k, mindiff);
    }
    public static ArrayList<ArrayList<Integer>> two_sum_bst(Node root1,Node root2,int target){
        ArrayList<ArrayList<Integer>> main = new ArrayList<>();
        if(root1==null || root2==null){
            return main;
        }
        Stack<Node> s1 = new Stack<>();
        Stack<Node> s2 = new Stack<>();
        Node top1,top2;
        while(true){
            while(root1!=null){
                s1.push(root1);
                root1=root1.left;
            }
            while(root2!=null){
                s2.push(root2);
                root2=root2.right;
            }
            if(s1.isEmpty() || s2.isEmpty()) break;
            top1 = s1.peek();
            top2 = s2.peek();
            if(top1.data + top2.data == target){
                ArrayList<Integer> list = new ArrayList<>();
                list.add(top1.data);
                list.add(top2.data);
                main.add(list);
                s1.pop();
                s2.pop();
                root1 = top1.right;
                root2 = top2.left; 
            }else if(top1.data + top2.data < target){
                s1.pop();
                root1 = top1.right;
            }else{
                s2.pop();
                root2 = top2.left;
            }
        }
        return main;
    }
    public static Node createBST(int arr[],int si,int ei){
        if(si>ei) return null;
        //mid
        int mid = si+(ei-si)/2;
        Node root = new Node(arr[mid]);
        root.left = createBST(arr, si, mid-1);
        root.right = createBST(arr, mid+1, ei);
        return root;
    }
    public static void main(String[] args) {
        Node root1 = new Node(5);
        root1.left = new Node(3);
        root1.left.left = new Node(2);
        root1.left.right = new Node(4);

        root1.right = new Node(7);
        root1.right.left = new Node(6);
        root1.right.right = new Node(8);

        Node root2 = new Node(10);
        root2.left = new Node(6);
        root2.left.left = new Node(3);
        root2.left.right = new Node(8);

        root2.right = new Node(15);
        root2.right.left = new Node(11);
        root2.right.right = new Node(18);
        System.out.println(two_sum_bst(root1,root2,16));
    }
}
//java BST.java