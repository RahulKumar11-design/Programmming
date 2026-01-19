package advDS.tree;
public class SegmentedTree {
    static int tree[];
    public static void init(int n){
        tree = new int[4*n];
    }
    public static int buildST(int[] arr,int i,int start,int end){
        if(start==end){
            return tree[i] = arr[start];
        }
        int mid = start+(end-start)/2;
        buildST(arr,2*i+1,start,mid);//left subtree - 2*i+1
        buildST(arr, 2*i+2, mid+1, end);//right subtree - 2*i+2

        return tree[i] = tree[2*i+1]+tree[2*i+2];
    }
    public static int getSumUtil(int i,int si,int sj,int qi,int qj){
        if(qj<si || sj<qi){
            return 0;//no overlapping
        }else if(qi<=si && sj<=qj){
            return tree[i];//overlapping
        }
        //partial overlapping
        int mid = si+(sj-si)/2;
        int left = getSumUtil(2*i+1, si, mid, qi, qj);
        int right = getSumUtil(2*i+2, mid+1, sj, qi, qj);

        return left+right;
    }
    public static int getSum(int arr[],int qi,int qj){
        int n = arr.length;
        init(n);
        buildST(arr, 0, 0, n-1);

        return getSumUtil(0,0,n-1,qi,qj);
    }
    public static void updateUtil(int i,int si,int sj,int idx,int diff){
        if(idx<si || idx>sj){
            return;
        }
        tree[i]+=diff;
        if(si!=sj){
            int mid = si+(sj-si)/2;
            updateUtil(2*i+1, si, mid, idx, diff);//left
            updateUtil(2*i+2, mid+1, sj, idx, diff);//rigth
        }
    }
    public static void update(int[] arr,int idx,int newValue){
        int diff = newValue-arr[idx];

        arr[idx]=newValue;
        updateUtil(0,0,arr.length-1,idx,diff);
    }
    //--------------------------------------------------------------
    public static void printarr(int[] arr){
        for(int i=0;i<arr.length;i++){
            System.out.print(arr[i]+" ");
        }
    }
    public static void buildST_max(int[] arr,int i,int si,int sj){
        if(si==sj){
            tree[i] = arr[si];
            return;
        }
        int mid = si+(sj-si)/2;

        buildST_max(arr, 2*i+1, si,mid);//left
        buildST_max(arr, 2*i+2,mid+1, sj);//right

        tree[i] = Math.max(tree[2*i+1],tree[2*i+2]);
    }
    public static int getmaxUtil(int i,int si,int sj,int qi,int qj){
        if(qj<si || sj<qi){
            return Integer.MIN_VALUE;
        }else if(si>=qi && sj<=qj){
            return tree[i];
        }
        int mid = si+(sj-si)/2;
        int left = getmaxUtil(2*i+1, si, mid, qi, qj);
        int right = getmaxUtil(2*i+2, mid+1, sj, qi, qj);

        return Math.max(left,right);
    }
    public static int getmax(int arr[],int qi,int qj){
        return getmaxUtil(0,0,arr.length-1,qi,qj);
    }
    public static void update1Util(int i,int si,int sj,int idx,int newValue){
        if(idx<si || idx>sj){
            return;
        }else if(si==sj){
            tree[i]=newValue;
            return;
        }
        tree[i] = Math.max(newValue,tree[i]);
        
        int mid = si+(sj-si)/2;
        update1Util(2*i+1, si, mid, idx, newValue);
        update1Util(2*i+2, mid+1, sj, idx, newValue);
    }
    public static void update1(int arr[],int idx,int newValue){
        arr[idx]=newValue;
        update1Util(0,0, arr.length-1,idx ,newValue);
    }
    public static void main(String[] args){
        // int arr[] = {1,2,3,4,5,6,7,8};
    }
}
//java SegmentedTree.java
