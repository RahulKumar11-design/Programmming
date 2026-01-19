package advDS;
import java.util.*;
public class QueueB {
    public static void first_non_repeatingLetter(String s){
        int freq[] = new int[26];
        Queue<Character> q = new LinkedList<>();
        for(Character c:s.toCharArray()){
            freq[c-'a']++;
            q.add(c);
            while(!q.isEmpty() && freq[q.peek()-'a']>1){
                q.remove();
            }
            if(q.isEmpty()){
                System.out.print(-1+" ");
            }else{
                System.out.print(q.peek()+" ");
            }
        }
        System.out.println();
    }
    public static void interleave_2Halves_of_queue(Queue<Integer> q){
        //size
        int n=q.size();
        //new queue
        Queue<Integer> first = new LinkedList<>();int i=1;
        while(i<=n/2){
            first.add(q.remove());
            i++;//
        }
        //interleaving
        while(!first.isEmpty()){
            q.add(first.remove());
            q.add(q.remove());
        }
    }
    public static void generateBinStr(int n){
        //bruteforce TC->O(nlogn)
        for(int i=1;i<=n;i++){
            int temp=i;
            String str="";
            while(temp>0){
                if((temp&1)!=0){
                    str="1"+str;
                }else{
                    str="0"+str;
                }
                temp=temp>>1;
            }
            System.out.println(str);
        }
    }
    public static void rev_k_elements(Queue<Integer> q,int k){
        Stack<Integer> s = new Stack<>();
        int i=1;int size=q.size();
        while(i<=k){
            s.push(q.remove());
            i++;
        }
        while(!s.empty()){
            q.add(s.pop());
        }
        i=1;
        while(i<=size-k){
            q.add(q.remove());
            i++;
        }
    }
    public static void slidingWinMax(int arr[],int k){
        Deque<Integer> d = new LinkedList<>();
        int n = arr.length;
        //sliding window 1
        d.add(0);
        for(int i=1;i<k;i++){
            while(!d.isEmpty() && arr[d.getLast()]<=arr[i]){
                d.removeLast();
            }
            d.addLast(i);
        }
        System.out.print(arr[d.peek()]+" ");
        System.out.println(d);
        //other sliding window
        for(int i=k;i<n;i++){
            while(!d.isEmpty() && d.peek()<=i-k){
                d.removeFirst();
            }
            while(!d.isEmpty() && arr[d.getLast()]<=arr[i]){
                d.removeLast();
            }
            d.addLast(i);
            System.out.print(arr[d.peek()]+" ");
            System.out.println(d);
        }
    }
    public static void main(String[] args) {
        int arr[] = {3,5,6,5,4,3,19,7,8,20,10};
        slidingWinMax(arr,4);
    }
}
