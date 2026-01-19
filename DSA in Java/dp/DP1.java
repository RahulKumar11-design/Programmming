package dp;
import java.util.*;

public class DP1 {
    //Type 1 ----------------------------------------------------------
    public static int fib(int n,int f[]){
        if(n==0 || n==1){
            return n;
        }
        if(f[n]!=0){
            return f[n];
        }
        f[n] = fib(n-1,f)+fib(n-2,f);
        return f[n];
    }
    //memoization - O(n)
    public static int ways(int n,int[] ways){
        if(n==0){
            return 1;
        }else if(n<0){
            return 0;
        }
        if(ways[n]!=-1){
            return ways[n];
        }
        ways[n] = ways(n-1, ways) + ways(n-2, ways);
        return ways[n];
    }
    //tabulation - O(n)
    public static int tabWays(int n){
        int dp[] = new int[n+1];
        dp[0]=1;
        for(int i=1;i<=n;i++){
            if(i==1){
                dp[i]=dp[i-1]+0;
            }else{
                dp[i]=dp[i-1]+dp[i-2];
            }
        }
        return dp[n];
    }
    //Type 2 ------------------------------------------------------------
    public static int Knapsack(int val[],int wt[],int W,int n,int dp[][]){
        if(W==0 || n==0){
            return 0;
        }
        if(dp[n][W]!=-1){
            return dp[n][W];
        }

        if(wt[n-1]<=W){ //valid 
            //include
            int ans1 = val[n-1]+Knapsack(val, wt, W-wt[n-1], n-1,dp);
            //exclude
            int ans2 = Knapsack(val, wt, W, n-1,dp);

            dp[n][W] = Math.max(ans1,ans2);
            return dp[n][W];
        }else{          //invalid
            dp[n][W] = Knapsack(val, wt, W, n-1,dp);
            return dp[n][W];
        }
    }
    public static int knapsackTab(int val[],int wt[],int W,int n){
        int dp[][] = new int[val.length+1][W+1];
        //base case
        for(int i=0;i<dp.length;i++){
            dp[i][0]=0;//0th col
        }
        for(int j=0;j<dp[0].length;j++){
            dp[0][j]=0;//0th row
        }
        //tabulation   ->  O(n*W)
        for(int i=1;i<n+1;i++){
            for(int j=1;j<W+1;j++){
                int v = val[i-1]; //ith item
                int w = wt[i-1];  //ith wt
                if(w<=j){         //valid
                    int incProfit = v+dp[i-1][j-w];
                    int excProfit = dp[i-1][j];

                    dp[i][j] = Math.max(incProfit,excProfit);
                }else{            //invalid
                    int excProfit = dp[i-1][j];
                    dp[i][j]=excProfit;
                } 
            }
        }
        return dp[n][W];
    }
    public static boolean targetSum_subset_tabulation(int arr[],int sum){
        int n = arr.length;
        boolean dp[][] = new boolean[n+1][sum+1];
        for(int i=0;i<n+1;i++){
            dp[i][0]=true;
        }

        //tabulation
        for(int i=1;i<dp.length;i++){
            for(int j=1;j<dp[0].length;j++){
                int val = arr[i-1];
                if(val<=j && dp[i-1][j-val]==true){
                    dp[i][j]=true;
                }else if(dp[i-1][j]==true){
                    dp[i][j]=true;
                }
            }
        }

        return dp[n][sum];
    }
    //Type 3 ---------------------------------------------------------------------
    public static int unbounded_Knapsack(int val[],int wt[],int W){
        int n = val.length;
        //Step 1 - table
        int dp[][] = new int[n+1][W+1];

        //Step 2 - initialisation && meaning
        //by default in java
        
        //Step 3 - filling
        for(int i=1;i<n+1;i++){
            for(int j=1;j<W+1;j++){
                int wgt=wt[i-1];
                if(wgt<=j){
                    dp[i][j] = Math.max(dp[i][j-wgt]+val[i-1],dp[i-1][j]);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][W];
    }
    public static int Ways_CoinExchange(int coins[],int sum){
        int n = coins.length;
        int W = sum;
        int dp[][] = new int[n+1][W+1];
        //(not possible -> 0) 0th row
        //possible but not need of coins means sum=0 -> (1) 0th col
        for(int i=0;i<n+1;i++){
            dp[i][0] = 1;
        }

        //tabulation
        for(int i=1;i<n+1;i++){
            for(int j=1;j<W+1;j++){
                if(coins[i-1]<=j){
                    dp[i][j] = dp[i][j-coins[i-1]]+dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][W];
    }
    //Type 4 -------------------------------------------------------------------------
    public static int long_subseq(String str1,String str2,int m,int n,int[][] dp){
        if(m==0 || n==0){
            return 0;
        }

        if(dp[m][n]!=-1){
            return dp[m][n];
        }

        if(str1.charAt(m-1)==str2.charAt(n-1)){
            dp[m][n] = long_subseq(str1, str2, m-1, n-1,dp)+1;
            return dp[m][n];
        }else{
            int ans1 = long_subseq(str1, str2, m-1, n,dp);

            int ans2 = long_subseq(str1, str2, m, n-1,dp);

            dp[m][n] = Math.max(ans1,ans2);
            return dp[m][n];
        }
    }
    public static int lcs_tab(String str1,String str2){

        int dp[][] = new int[str1.length()+1][str2.length()+1];

        for(int i=1;i<str1.length()+1;i++){
            for(int j=1;j<str2.length()+1;j++){
                if(str1.charAt(i-1)==str2.charAt(j-1)){
                    dp[i][j] = dp[i-1][j-1]+1;
                }else{
                    int ans1 = dp[i-1][j];
                    int ans2 = dp[i][j-1];

                    dp[i][j] = Math.max(ans1,ans2);
                }
            }
        }
        
        return dp[str1.length()][str2.length()];
    }
    public static int longest_Common_substring(String str1,String str2){
        int n = str1.length();
        int W = str2.length();
        int dp[][] = new int[n+1][W+1];
        int max=0;

        for(int i=1;i<n+1;i++){
            for(int j=1;j<W+1;j++){
                if(str1.charAt(i-1)==str2.charAt(j-1)){
                    dp[i][j] = dp[i-1][j-1]+1;
                    max = Math.max(dp[i][j],max);
                }else{
                    //break seq and start next
                    dp[i][j]=0;
                }
            }
        }

        return max;
    }
    public static int lcs(int[] arr1,int[] arr2){
        
        int dp[][] = new int[arr1.length+1][arr2.length+1];

        for(int i=1;i<arr1.length+1;i++){
            for(int j=1;j<arr2.length+1;j++){
                if(arr1[i-1]==arr2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }else{
                    int ans1 = dp[i-1][j];
                    int ans2 = dp[i][j-1];

                    dp[i][j] = Math.max(ans1,ans2);
                }
            }
        }
        
        return dp[arr1.length][arr2.length];
    }
    public static int lis(int arr[]){
        //longest Increasing Subsequence
        TreeSet<Integer> set = new TreeSet<>();
        for(int i:arr){
            set.add(i);
        }
        int arr2[] = new int[set.size()];

        Iterator<Integer> it=set.iterator();
        int i=0;
        while(it.hasNext()){
            arr2[i++]=it.next();
        }
        return lcs(arr, arr2);
    }
    public static int edit_rec(String str1,String str2,int n,int m,int dp[][]){
        if(n==0){
            return m;
        }else if(m==0){
            return n;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }

        if(str1.charAt(n-1)==str2.charAt(m-1)){
            dp[n][m] = edit_rec(str1,str2,n-1,m-1,dp);
            return dp[n][m];
        }else{
            int insert = edit_rec(str1, str2, n, m-1,dp)+1;
            int remove = edit_rec(str1, str2, n-1, m,dp)+1;
            int replace = edit_rec(str1, str2, n-1, m-1,dp)+1;

            dp[n][m] = Math.min(insert,Math.min(remove,replace));
            return dp[n][m];
        }
    }
    public static int editDistance(String str1,String str2){
        int n = str1.length();
        int m = str2.length();
        int dp[][] = new int[n+1][m+1];

        //initialisation
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                if(i==0){
                    dp[0][j]= j;
                }else if(j==0){
                    dp[i][0]=i;
                }
            }
        }
        //tabulation
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(str1.charAt(i-1)==str2.charAt(j-1)){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    int add = dp[i][j-1]+1;
                    int remove = dp[i-1][j]+1;
                    int replace = dp[i-1][j-1]+1;

                    dp[i][j] = Math.min(add,Math.min(remove,replace));
                }
            }
        }
        return dp[n][m];
    }
    public static int StringConversion(String str1,String str2){
        //lcs length
        int lcs = lcs_tab(str1, str2);

        //del operation
        int del = str1.length()-lcs;

        //add operation
        int add = str2.length()-lcs;

        return del+add;
    }
    public static boolean isMatch(String s,String p){
        int n = s.length();
        int m = p.length();

        boolean dp[][] = new boolean[n+1][m+1];
        //initialise
        dp[0][0]=true;

        for(int j=1;j<m+1;j++){
            //i=0 : s = ""
            if(p.charAt(j-1)=='*'){
                dp[0][j]=dp[0][j-1];
            }
        }
        //tabulation
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                //case 1
                if(s.charAt(i-1)==p.charAt(j-1) || p.charAt(j-1)=='?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                //case 2: * = "assda" || "" || "a"
                else if(p.charAt(j-1)=='*'){
                    boolean ignore = dp[i][j-1];//ignore *(s)
                    boolean match = dp[i-1][j];//match chars(s-1)

                    dp[i][j] = ignore||match;
                }
                //case 3:not match or symbol
            }
        }
        return dp[n][m];
    }
    //Type 5 ---------------------------------------------------------------
    public static int catalanMemo(int n,int dp[]){
        if(n==1 || n==0) return 1;
        if(dp[n]!=-1) return dp[n];
        int ans = 0;
        for(int i=0;i<n;i++){
            ans+=catalanMemo(i,dp)*catalanMemo(n-i-1,dp);
        }
        return dp[n]=ans;
    }
    public static int catalanTab(int n){
        //table
        int dp[] = new int[n+1];
        //initialise
        dp[0] = dp[1] = 1; 
        //filling bottom to up
        for(int i=2;i<n+1;i++){
            for(int j=0;j<i;j++){
                dp[i]+=dp[j]*dp[i-j-1];
            }
        }
        return dp[n];
    }
    public static int MountainRange(int n){
        //upstroke (/) and downstroke (\)
        int dp[] = new int[n+1];
        dp[0] = dp[1] = 1;

        for(int i=2;i<n+1;i++){
            for(int j=0;j<i;j++){
                int inner_pairs = dp[j];
                int outer_pairs = dp[i-j-1];
                dp[i]+=inner_pairs*outer_pairs; 
            }
        }

        return dp[n];
    }
    //Type 6 ------------------------------------------------------------------
    public static int minCost_formingMatrix(int[] arr,int i,int j){
        if(i==j){
            return 0;//single matrix
        }
        int ans = Integer.MAX_VALUE;
        for(int k=i;k<=j-1;k++){
            int cost1 = minCost_formingMatrix(arr, i, k);//Ai....Ak => arr[i-1]*arr[k]
            int cost2 = minCost_formingMatrix(arr, k+1, j);//Ak+1....Aj => arr[k]*arr[j]

            int cost3 = arr[i-1]*arr[k]*arr[j];
            int finalcost = cost1+cost2+cost3;
            ans = Math.min(ans,finalcost);
        }
        return ans;//mincost
    }
    public static int mcmMemo(int[] arr,int i,int j,int[][] dp){
        if(i==j){
            return 0;//single matrix
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans = Integer.MAX_VALUE;
        for(int k=i;k<=j-1;k++){
            int cost1 = mcmMemo(arr, i, k,dp);//Ai....Ak => arr[i-1]*arr[k]
            int cost2 = mcmMemo(arr, k+1, j,dp);//Ak+1....Aj => arr[k]*arr[j]

            int cost3 = arr[i-1]*arr[k]*arr[j];
            int finalcost = cost1+cost2+cost3;
            ans = Math.min(ans,finalcost);
        }
        return dp[i][j] = ans;//mincost
    }
    public static int mcmTab(int arr[],int n){
        int dp[][] = new int[n][n];
        //initialise
        for(int i=0;i<n;i++){
            dp[i][i]=0;
        }

        for(int len=2;len<=n-1;len++){
            for(int i=1;i<=n-len;i++){
                int j = i+len-1;
                dp[i][j] = Integer.MAX_VALUE;
                for(int k=i;k<j;k++){
                    int cost1 = dp[i][k];//Ai...Ak
                    int cost2 = dp[k+1][j];//Ak+1...Aj

                    int cost3 = arr[i-1]*arr[k]*arr[j];
                    dp[i][j] = Math.min(dp[i][j],cost1+cost2+cost3);
                }
            }
        }
        return dp[1][n-1];
    }
    public static int minJumps(int[] arr){
        //tabulation
        int dp[] = new int[arr.length];
        //initialise
        Arrays.fill(dp,-1);
        dp[arr.length-1]=0;
        //filling
        for(int i=arr.length-2;i>=0;i--){
            int steps = arr[i];
            int min = Integer.MAX_VALUE;
            for(int j=i+1;j<=i+steps && j<arr.length;j++){
                if(dp[j]!=-1){
                    min = Math.min(min,dp[j]+1);
                }
            }
            if(min!=Integer.MAX_VALUE){
                dp[i]=min;
            }
        }
        return dp[0];//dp[i] -> i---n-1 jumps
    }
    public static void main(String[] args) {
        int arr[] = {2,3,1,1,4};
        System.out.println(minJumps(arr));
    }
}
//java DP1.java
