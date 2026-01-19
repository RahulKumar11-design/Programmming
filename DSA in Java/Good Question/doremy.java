public class doremy {
    public static int rec(int arr[],int q,int i){
        if(q<=0) return 0;
        else if(i==arr.length) return 0;

        if(arr[i]<=q){
            return 1+rec(arr,q,i+1);
        }else{
            int inc = 1+rec(arr,q-1,i+1);
            int exc = 0 + rec(arr,q,i+1);
            return Math.max(inc,exc);
        }
    }
    public static void main(String[] args) {
        int contest[] = {8,9,5,5,5,7,7,5,5,5,8,4,4,4};
        int iq=5;
        int n = contest.length;

        int dp[][] = new int[n][iq+1];
        //initialize
        for(int j=1;j<=iq;j++){
            dp[n-1][j]=1;
        }
        for(int i=n-2;i>=0;i--){
            for(int j=1;j<=iq;j++){
                if(contest[i]<=j){
                    dp[i][j] = 1 + dp[i+1][j];
                }else{
                    int exc = 0 + dp[i+1][j];
                    int inc = 1 + dp[i+1][j-1];
                    dp[i][j]=Math.max(exc,inc);
                }
            }
        }
        for(int j=0;j<=iq;j++){
            for(int i=0;i<n;i++){
                System.out.print(dp[i][j]+" ");
            }System.out.println();
        }
        String ans = "";
        int i=0,j=iq;
        while(i<n-1 && j>=0){
            if(contest[i]<=j){
                ans+='1';
            }else{
                if(dp[i+1][j-1]>=dp[i+1][j]){
                    ans+='1';
                    j--;
                }else{
                    ans+='0';
                }
            }
            i++;
        }
        if(j>=1){
            ans+='1';
        }else{
            ans+='0';
        }
        System.out.println(ans);
    }
}
