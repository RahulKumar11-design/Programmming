public class stocks {
    public static int rec(int[] prices,int i,int buy,int k,int[][][] dp){
        if(k==0 || i==prices.length){
            return 0;
        }
        if(dp[i][buy][k]!=-1){
            return dp[i][buy][k];
        }
        if(buy==0){
            int buy_ = -prices[i]+rec(prices,i+1,1,k,dp);
            int skip = rec(prices,i+1,0,k,dp);
            return dp[i][buy][k] = Math.max(buy_,skip);
        }else{
            int sell = prices[i]+rec(prices,i+1,0,k-1,dp);
            int skip = rec(prices,i+1,1,k,dp);
            return dp[i][buy][k] = Math.max(sell,skip);
        }
    }
    public static int maxProfit(int[] prices) {
        int n = prices.length;
        int dp[][][] = new int[n][2][3];

        //initialise
        dp[n-1][1][1]=prices[n-1];
        dp[n-1][1][2]=prices[n-1];
        for(int i=n-2;i>=0;i--){//days
            for(int j=0;j<=1;j++){//buy / sell
                for(int k=1;k<=2;k++){//condition of atmost 2
                    if(j==0){
                        int buy = -prices[i]+dp[i+1][1][k];
                        int skip = dp[i+1][0][k];
                        dp[i][j][k] = Math.max(buy,skip);
                    }else{
                        int sell = prices[i]+dp[i+1][0][k-1];
                        int skip = dp[i+1][1][k];
                        dp[i][j][k] = Math.max(sell,skip);
                    }
                }
            }
        }
        for(int i=0;i<dp.length;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<=2;k++){
                    System.out.print(dp[i][j][k]+" ");
                }
                System.out.println();
            }
            System.out.println();
        }
        return dp[0][0][2];
    }
    public static void hello() {
        // Scanner sc = new Scanner();
        int arr[] = {0,0,0,0,1,1,1};
        int n = arr.length;
        int ones=0,r=n-1;
        int ans[] = new int[n];
        int j=0;
        while(r>=0){
            while(r>=0 && arr[r]!=0){
                r--;ones++;
            }
            if(j>0){
                // System.out.println(j+" "+ones+" "+ans[j+1]);
                ans[j]+=ones+ans[j-1];
            }else{
                ans[j]+=ones;
            }
            r--;
            j++;
        }
        for(int i=j;i<n;i++){
            ans[i]=-1;
        }
        for(int i=0;i<n;i++){
            System.out.print(ans[i]+" ");
        }
        
    }
    public static void main(String[] args) {
        int arr[] = {0,3,1,4,0,5};
        maxProfit(arr);
    }
}