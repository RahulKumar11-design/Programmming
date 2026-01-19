package advDS;
import java.util.*;

public class HashQues {
    public static void maj_nb3(int[] nums){
        HashMap<Integer,Integer> map = new HashMap<>();
        for(int i=0;i<nums.length;i++){
            map.put(nums[i],map.getOrDefault(nums[i], 0)+1);
        }

        for (Integer i : map.keySet()) {
            if(map.get(i)>nums.length/3){
                System.out.print(i+" ");
            }
        }
    }
    public static boolean isAnagram(String s,String t){
        if(s.length()!=t.length()){
            return false;
        }
        HashMap<Character,Integer> map = new HashMap<>();
        for (Character c:s.toCharArray()) {
            map.put(c,map.getOrDefault(c,0)+1);
        }
        for ( Character c:t.toCharArray()) {
            if(map.containsKey(c)){
                if(map.get(c)==1){
                    map.remove(c);
                }else{
                    map.put(c,map.get(c)-1);
                }
            }else{
                return false;
            }
        }
        return map.isEmpty();
    }
    public static void journey_Tickets(HashMap<String,String> map){  //O(n)
        //reverse mapping
        HashMap<String,String> revmap = new HashMap<>();
        for ( String s : map.keySet()) {
            revmap.put(map.get(s),s);
        }
        // find starting point
        String st="";
        Set<String> keys = map.keySet();
        for (String s : keys) {
            if(!revmap.containsKey(s)){
                st=s;
            }
        }
        while(st!=null){
            System.out.print(st+"->");
            st = map.get(st);
        }System.out.println("null");
    } 
    public static void largest_subarrayS0(int[] arr){   //(0)
        //sum(i+1,j) = sum(j)-sum(i)
        //sum(i+1,j)=0,sum(i)=sum(j)  -> track by mapping
        HashMap<Integer,Integer> map = new HashMap<>();
        //(sum,i)
        map.put(0,-1);//initialze
        int sum=0;
        int l=0;
        for(int j=0;j<arr.length;j++){
            sum+=arr[j];
            if(map.containsKey(sum)){
                l = Math.max(l,j-map.get(sum));
            }else{
                map.put(sum,j);
            }
        }
        System.out.println("max length with subarray (sum as 0) : "+l);
    }
    public static void No_subarrays_sum_k(int arr[],int k){  //O(n)
        HashMap<Integer,Integer> map = new HashMap<>();
        //(sum,freq)
        map.put(0,1);//as if arr[0]=k ,it should count as subarray (sum(j)-k=k-k=0)
        int sum=0;
        int ans = 0;
        for(int j=0;j<arr.length;j++){
            sum+=arr[j];
            if(map.containsKey(sum-k)){
                ans+=map.get(sum-k);
            }else{
                map.put(sum,map.getOrDefault(sum,0)+1);
            }
        }
        System.out.print("No. of subarrays with sum as "+k+" = "+ans);
    }
    static class pair implements Comparable<pair>{
        int v;
        String s;
        pair(int v,String s){
            this.v=v;
            this.s=s;
        }
        @Override
        public int compareTo(pair p2){
            return this.s.compareTo(p2.s);
        }
    }
    public static void main(String[] args) {
        // int arr[] = {10,2,-2,-20,10};
        // String s[] = {"10","2","-2","-20","10"};
        // TreeMap<pair,Integer> map = new TreeMap<>();
        // for(int i=0;i<arr.length;i++){
        //     map.put(new pair(i,s[i]),arr[i]);
        // }
        // HashMap<int[],ArrayList<String>> map = new HashMap<>();
    }
}
//java HashQues.java