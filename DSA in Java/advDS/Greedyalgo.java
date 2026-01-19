package advDS;
import java.util.*;
import java.util.Arrays;
public class Greedyalgo {
    public static void activitySelection(){
        int start[] = {0,3,1,5,8,5};
        int end[] = {6,4,2,7,9,9};
        //sorting
        int activities[][] = new int[start.length][3];
        for(int i=0;i<start.length;i++){
            activities[i][0]=i;
            activities[i][1]=start[i];
            activities[i][2]=end[i];
        }
        Arrays.sort(activities,Comparator.comparingDouble(o -> o[2]));
        int maxAct=0;
        //first activity
        ArrayList<Integer> list = new ArrayList<>();
        maxAct=1;
        list.add(activities[0][0]);
        int lastEnd=activities[0][2];
        for(int i=1;i<start.length;i++){
            if(activities[i][1]>lastEnd){
                maxAct++;
                list.add(activities[i][0]);
                lastEnd=activities[i][2];
            }
        }
        System.out.println("No. of activities = "+maxAct);
        for(int i=0;i<list.size();i++){
            System.out.print("A"+list.get(i)+" ");
        }System.out.println();
    }
    public static void fracKnapsack(int val[],int weight[],int W){
        int capacity= W;
        //sorting ascending
        double ratio[][] = new double[val.length][2];
        //0->idx //1->ratio
        for(int i=0;i<val.length;i++){
            ratio[i][0]=i;
            ratio[i][1]=(double)val[i]/weight[i];
        }
        Arrays.sort(ratio,Comparator.comparingDouble(o->o[1]));

        int maxVal=0;
        for(int i=val.length-1;i>=0;i--){
            int idx = (int)ratio[i][0];
            if(capacity>weight[idx]){
                capacity-=weight[idx];
                maxVal+=val[idx];
            }else{
                maxVal+=(int)ratio[i][1] * capacity;
                break;
            }
        }
        System.out.println("max value in knapsack = "+maxVal);
    }
    static class Job{
        int deadline;
        int profit;
        char id;
        public Job(int d,int p,char i){
            deadline=d;profit=p;id=i;
        }
    }
    public static void jobSeq(){
        int jobInfo[][] = {{4,40},{1,10},{2,20},{1,30}};
        int maxjobs=0;
        ArrayList<Job> jobs = new ArrayList<>(); 
        for(char i='a';i-'a'<jobInfo.length;i++){
            jobs.add(new Job(jobInfo[i-'a'][0],jobInfo[i-'a'][1], i));
        }
        //sorting in decreasing order
        Collections.sort(jobs,(a,b) -> b.profit-a.profit);

        int time=0;
        ArrayList<Character> seq = new ArrayList<>();
        for(int i=0;i<jobs.size();i++){
            Job curr = jobs.get(i);
            if(curr.deadline>time){
                seq.add(curr.id);
                maxjobs++;
                time++;
            } 
        }

        System.out.println("max no. of jobs done = "+maxjobs);
        System.out.println(seq);
    }
    public static void ChochoProb(){
        int verCost[] = {2,1,3,1,4};
        int horCost[] = {4,1,2};
        Arrays.sort(verCost);
        Arrays.sort(horCost);

        int h=horCost.length-1;int v=verCost.length-1;int hp=1;int vp=1;
        int cost=0;
        while(h>=0 && v>=0){
            if(verCost[v]<=horCost[h]){
                cost+=vp*horCost[h];
                h--;hp++;
            }else{
                cost+=hp*verCost[v];
                v--;vp++;
            }
        }
        while(h>=0){
            cost+=vp*horCost[h];
            h--;hp++;
        }
        while(v>=0){
            cost+=hp*verCost[v];
            v--;vp++;
        }
        System.out.println(cost);
    }
    public static void maxBalStr(String str){
        int l=0;int r=0;
        int count=0;
        for(int i=0;i<=str.length();i++){
            if(i<str.length() && str.charAt(i)=='L'){
                l++;
            }else if(i<str.length() && str.charAt(i)=='R'){
                r++;
            }
            if(l==r){
                count++;
                l=0;r=0;
            }
        }
        System.out.println(count);
    }
    public static void smallString_N_sum_k(int n,int k){
        String ans = "";
        while(k>26){
            ans+='z';
            k-=26;n--;
        }
        char c = (char)(k-n+1+('a'-1));
        ans = c + ans;
        n--;
        while(n>0){
            ans = 'a' + ans;
            n--;
        }
        System.out.println(ans);
    }
    static int ans=10000;
    public static void find_min_maxsum_subarray(int[] arr,int k,int n,int idx,int sum,int maxsum){
        if(k==1){
            sum=0;
            for(int i=idx;i<n;i++){
                sum+=arr[i];
            }
            maxsum=Math.max(maxsum,sum);
            ans=Math.min(ans,maxsum);
            return;
        }
        sum=0;
        for(int i=idx;i<n;i++){
            sum+=arr[i];
            maxsum=Math.max(maxsum,sum);
            find_min_maxsum_subarray(arr, k-1,n, i+1, sum, maxsum);
        }
    }
    public static void main(String[] args) {
        int arr[] = {1,20,18,10,21,21,11};
        int n = arr.length;
        find_min_maxsum_subarray(arr,4,n,0,0,0);
        System.out.println(ans);
    }
}
//java Greedyalgo.java
