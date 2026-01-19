import java.util.*;

class bin{
    public static void main(String[] args){
        int arr[] = {0,1,0};
        int n = arr.length;
        int ans[] = new int[n];
        int j=0,i=n-1;
        int ones=0;
        while(i>=0){
            while(i>=0 && arr[i]!=0){
                i--;
                ones++;
            }
            if(i>=0){
                if(j>0){
                    ans[j]=ones+ans[j-1];
                }else{
                    ans[j]=ones;
                }
                j++;
            }
            i--;
        }

        for(int k=j;k<n;k++){
            ans[k]=-1;
        }

        for(int k=0;k<ans.length;k++){
            System.out.print(ans[k]+" ");
        }
    }
}