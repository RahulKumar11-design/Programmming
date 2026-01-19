package advDS.tree;
import java.util.*;

public class BinaryTreeB {
    static class Node{
        int data;
        Node left;
        Node right;
        public Node(int data){
            this.data=data;
            this.left=null;
            this.right=null;
        } 
    }
    static class BinaryTree{
        static int idx=-1;
        public Node buildTree(int nodes[]){
            idx++;
            if(nodes[idx]==-1){
                return null;
            }
            Node newNode = new Node(nodes[idx]);
            newNode.left=buildTree(nodes);
            newNode.right=buildTree(nodes);
            return newNode;
        }
        public void preorder(Node root){  //O(n)
            if(root==null){
                return;
            }
            System.out.print(root.data+" ");
            preorder(root.left);
            preorder(root.right);
        } 
        public void inorder(Node root){
            if(root==null){
                return;
            }
            inorder(root.left);
            System.out.print(root.data+" ");
            inorder(root.right);
        }
        public void postorder(Node root){
            if(root==null){
                return;
            }
            postorder(root.left);
            postorder(root.right);
            System.out.print(root.data+" ");
        }
        //levelOrder
        public void levelOrder(Node root){
            if(root==null){
                return;
            }
            Queue<Node> q = new LinkedList<>();
            q.add(root);
            q.add(null);
            while(!q.isEmpty()){
                Node currNode = q.remove();
                if(currNode==null){
                    System.out.println();
                    if(q.isEmpty()){
                        break;
                    }else{
                        q.add(null);
                    }
                }else{
                    System.out.print(currNode.data+" ");
                    if(currNode.left!=null){
                        q.add(currNode.left);
                    }
                    if(currNode.right!=null){
                        q.add(currNode.right);
                    }
                }
            }
        }
        public int Height(Node root){
            if(root==null){
                return 0;
            }
            int lh = Height(root.left);
            int rh = Height(root.right);
            return Math.max(lh,rh)+1;
        }
        public int Count(Node root){
            if(root==null){
                return 0; 
            }
            int lcount = Count(root.left);
            int rcount = Count(root.right);
            return lcount+rcount+1;
        }
        public int Sum(Node root){
            if(root==null){
                return 0;
            }
            int lsum = Sum(root.left);
            int rsum = Sum(root.right);
            return lsum+rsum+root.data;
        }
        public int diameter2(Node root){ //O(n^2)
            if(root==null){
                return 0;
            }
            int ld = diameter2(root.left);
            int rd = diameter2(root.right);
            int lh = Height(root.left);
            int rh = Height(root.right);

            int selfdia = lh+rh+1;
            return Math.max(Math.max(ld,rd),selfdia);
        }
    }
    static class info{
        int dia;
        int hgt;
        public info(int dia,int hgt){
            this.dia=dia;
            this.hgt=hgt;
        }
    }
    public static info diameter(Node root){
        if(root==null){
            return new info(0, 0);
        }
        info leftInfo = diameter(root.left);
        info rightInfo = diameter(root.right);

        int dia = Math.max(Math.max(leftInfo.dia,rightInfo.dia),leftInfo.hgt+rightInfo.hgt+1);
        int hgt = Math.max(leftInfo.hgt,rightInfo.hgt)+1;
        return new info(dia, hgt);
    }
    public static boolean isIdentical(Node node,Node subRoot){
        if(node==null && subRoot==null){
            return true;
        }
        if(node==null || subRoot==null || node.data!=subRoot.data){
            return false;
        }
        if(!isIdentical(node.left, subRoot.left)){
            return false;
        }
        if(!isIdentical(node.right, subRoot.right)){
            return false;
        }

        return true;
    }
    public static boolean isSubtree(Node root,Node subRoot){
        if(root==null){
            return false;
        }
        if(root.data==subRoot.data){
            if(isIdentical(root,subRoot)){
                return true;
            }
        }

        boolean leftAns = isSubtree(root.left, subRoot);
        boolean rightAns = isSubtree(root.right, subRoot);
        return leftAns || rightAns;
    }
    static class pack{
        Node node;
        int horz;
        pack(Node node,int horz){
            this.node=node;
            this.horz=horz;
        }
    }
    public static void topView(Node root){
        if(root==null){
            return;
        }
        Queue<pack> q = new LinkedList<>();
        HashMap<Integer,Node> map = new HashMap<>();
        int min=0;int max=0;
        q.add(new pack(root, 0));
        q.add(null);
        //breadth first Search
        while(!q.isEmpty()){
            pack curr = q.remove();
            if(curr==null){
                if(q.isEmpty()){
                    break;
                }else{
                    q.add(null);
                }
            }else{
                if(!map.containsKey(curr.horz)){
                    min = Math.min(min,curr.horz);
                    max = Math.max(max,curr.horz);
                    map.put(curr.horz,curr.node);
                }
                if(curr.node.left!=null){
                    q.add(new pack(curr.node.left, curr.horz-1));
                }
                if(curr.node.right!=null){
                    q.add(new pack(curr.node.right, curr.horz+1));
                }
            }
        }
        for(int i=min;i<=max;i++){
            System.out.print(map.get(i).data+" ");
        }
    }
    public static boolean getPath(Node root,int n,ArrayList<Node> list){
        if(root==null){
            return false;
        }
        list.add(root);
        if(root.data==n){
            return true;
        }

        boolean foundleft = getPath(root.left, n, list);
        boolean foundright = getPath(root.right, n, list);

        if(foundleft || foundright){
            return true;
        }
        list.remove(list.size()-1);
        return false;
    }
    public static Node lca(Node root,int n1,int n2){
        ArrayList<Node> path1 = new ArrayList<>();
        ArrayList<Node> path2 = new ArrayList<>();

        getPath(root, n1, path1);
        getPath(root, n2, path2);

        //loop
        int i=0;
        for(;i<path1.size() && i<path2.size();i++){
            if(path1.get(i)!=path2.get(i)){//(list is of node) if value is same but we want path for specific node 
                break;
            }
        }
        // lca -> at idx(i-1)
        Node lca = path1.get(i-1);
        return lca;
    } 
    public static Node lca2(Node root,int n1,int n2){
        if(root==null || root.data==n1 || root.data==n2){
            return root;
        }

        Node leftLca = lca2(root.left, n1, n2);
        Node rightLca = lca2(root.right, n1, n2);

        if(rightLca==null){
            return leftLca;
        }
        if(leftLca==null){
            return rightLca;
        }

        return root;
    }
    public static int lcaDis(Node root,int n){
        if(root==null){
            return -1;
        }
        if(root.data==n){
            return 0;
        }

        int leftdis = lcaDis(root.left, n);
        int rightdis = lcaDis(root.right, n);

        if(leftdis==-1 && rightdis==-1){
            return -1;
        }
        if(leftdis==-1){
            return rightdis+1;
        }else{
            return leftdis+1;
        }

    }
    public static int minDis(Node root,int n1,int n2){
        Node lca = lca2(root, n1, n2);
        int dist1 = lcaDis(lca,n1);
        int dist2 = lcaDis(lca,n2);
        return dist1+dist2;
    }
    public static int KAncestor(Node root,int n,int k){
        if(root==null){
            return -1;
        }
        if(root.data==n){
            return 0;
        }
        int left = KAncestor(root.left, n, k);
        int right = KAncestor(root.right, n, k);
        if(left==-1 && right==-1){
            return -1;
        }

        int max = Math.max(left,right);
        if(max+1==k){
            System.out.println(root.data);
        }
        return max+1;
    }
    public static int Transform(Node root){
        if(root==null){
            return 0;
        }
        int leftSubtree = Transform(root.left);
        int rightSubtree = Transform(root.right);
        int data = root.data;
        int newleft = (root.left==null)?0:root.left.data;
        int newright = (root.right==null)?0:root.right.data;
        root.data = leftSubtree+newleft+rightSubtree+newright;
        return data;
    }
    public static Node delete_leafNodes(Node root,int x){
        if(root==null){
            return null;
        }
        root.left = delete_leafNodes(root.left, x);
        root.right = delete_leafNodes(root.right, x);

        if(root.left==null && root.right==null){
            if(root.data==x){
                return null;
            }
            return root;
        }
        return root;
    }
    public static void KthLevel(Node root,int level,int k){
        if (root==null) {
            return;
        }if(level==k){
            System.out.print(root.data+" ");
            return;
        }
        KthLevel(root.left, level+1, k);
        KthLevel(root.right, level+1, k);
    }
    public static void main(String args[]){
        int nodes[] = {1,2,4,-1,-1,5,-1,-1,3,6,-1,-1,7,-1,-1};
        BinaryTree tree = new BinaryTree();
        Node root = tree.buildTree(nodes);
        KthLevel(root, 0, 2);
    }
}
