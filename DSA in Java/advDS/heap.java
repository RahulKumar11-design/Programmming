package advDS;
import java.util.*;

public class heap {
    public static void heapify(int i,int size,int[] arr){
        int left = 2*i+1;
        int right = 2*i+2;
        int maxIdx = i;
        if(left<size && arr[left]>arr[maxIdx]){
            maxIdx = left;
        }
        if(right<size && arr[right]>arr[maxIdx]){
            maxIdx = right;
        }

        if(maxIdx!=i){
            //swap
            int temp = arr[i];
            arr[i] = arr[maxIdx];
            arr[maxIdx] = temp;

            heapify(maxIdx,size,arr);
        }
    }
    public static void heapSort(int[] arr){  // O(nlogn)
        //step 1: build max heap
        int n = arr.length;
        for(int i=n/2;i>=0;i--){
            heapify(i,n,arr);
        }

        //step 2: push largest at the end
        for(int i=n-1;i>0;i--){
            //swap
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            heapify(0,i,arr);
        }
    }
    public static void printarr(int arr[]){
        for(int i=0;i<arr.length;i++){
            System.out.print(arr[i]+" ");
        }
        System.out.println();
    } 
    static class point implements Comparable<point>{
        int x;
        int y;
        int distsq;
        int idx;
        point(int x,int y,int distsq,int idx){
            this.x=x;
            this.y=y;
            this.distsq=distsq;
            this.idx=idx;
        }
        @Override
        public int compareTo(point p2){
            return this.distsq - p2.distsq;
        }
    }
    public static void nearbyCar(int pts[][],int k){
        PriorityQueue<point> pq = new PriorityQueue<>();
        for(int i=0;i<pts.length;i++){
            int distsq = pts[i][0]*pts[i][0] + pts[i][1]*pts[i][1];
            pq.add(new point(pts[i][0],pts[i][1],distsq,i));
        }
        //nearest cars
        for(int i=0;i<k;i++){
            System.out.println("C"+pq.remove().idx);
        }
    }
    public static void min_cost_join_ropes(int ropes[]){
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int i=0;i<ropes.length;i++){
            pq.add(ropes[i]);
        }
        int minCost = 0;
        while(pq.size()>1){
            int rope1 = pq.remove();
            int rope2 = pq.remove();
            minCost+=rope1+rope2;
            pq.add(rope1+rope2);
        }
        System.out.println("Mincost of connecting N ropes = "+minCost);
    }
    static class info implements Comparable<info>{
        int idx;
        int Soldiers;
        info(int idx,int arr[]){
            this.idx=idx;
            for(int i=0;i<arr.length;i++){
                if(arr[i]==1){
                    this.Soldiers++;
                }
            }
        }
        @Override
        public int compareTo(info i2){
            if(this.Soldiers==i2.Soldiers){
                return this.idx-i2.idx;
            }
            return this.Soldiers-i2.Soldiers;
        }
    }
    public static void WeakestSoldier(int mat[][],int k){
        PriorityQueue<info> pq = new PriorityQueue<>();
        for(int i=0;i<mat.length;i++){
            pq.add(new info(i, mat[i]));
        }
        for(int i=0;i<k;i++){
            System.out.println("R"+pq.peek().idx);
            pq.remove();
        }
    }
    static class num implements Comparable<num>{
        int idx;
        int n;
        num(int idx,int n){
            this.idx=idx;
            this.n=n;
        }
        public int compareTo(num t2){
            return t2.n-this.n;
        }
    }
    public static void Sliding_Win_Max(int arr[],int k){
        int Win[] = new int[arr.length-k+1];
        PriorityQueue<num> pq = new PriorityQueue<>();
        // 1st window
        for(int i=0;i<k;i++){
            pq.add(new num(i,arr[i]));
        }
        Win[0]=pq.peek().n;int j=1;
        for(int i=k;i<arr.length;i++){
            System.out.println(pq);
            while(!pq.isEmpty() && pq.peek().idx<=i-k){
                pq.remove();
            }
            pq.add(new num(i,arr[i]));
            Win[j]=pq.peek().n;
            j++;
        }
        printarr(Win);
    }
    public static int minTime(int arr[],int n){
        boolean vis[] = new boolean[n+1];
        Queue<Integer> q = new LinkedList<>();
        for(int i=0;i<arr.length;i++){
            vis[arr[i]]=true;
            q.add(arr[i]);
        }
        int time=0;
        while(!q.isEmpty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                int curr = q.poll();
                if(curr-1>=1 && !vis[curr-1]){
                    vis[curr-1]=true;
                    q.add(curr-1);
                }
                if(curr+1<=n && !vis[curr+1]){
                    vis[curr+1]=true;
                    q.add(curr+1);
                }
            }
            time++;
        }
        return time-1;
    }
    public static void main(String[] args) {
        int arr[] = {2,6};
        System.out.println(minTime(arr, 6));
    }
}
// java heap.java