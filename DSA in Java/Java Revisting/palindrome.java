import java.util.*;
public class palindrome {
    public static int count(int arr[]){
        int ans = 0;

        for(int a:arr){
            int d=0,sum=0;
            //edge case
            if(a==0){
                d=1;
            }

            while(a>0){
                int r = a%10;
                d++;sum+=r;
                a/=10;
            }

            if(d%2==0){
                ans+=d*d;
            }else{
                ans+=sum;
            }
        }

        return ans;
    }
    public static int sumString(String s){
        int sum = 0;

        int freq[] = new int[26];
        
        for(int i=0;i<s.length();i++){
            freq[s.charAt(i)-'a']++;
        }

        for(int i=0;i<26;i++){
            sum+=(freq[i]*(i+'a'))%5;
        }

        return sum;
    }
    public static void main(String args[]){
        int arr[] = {2, 5, 9, 7, 4};

        int n = arr.length;

        ArrayList<Integer> peaks = new ArrayList<>();

        for(int i=1;i<n-1;i++){
            if(arr[i-1]<arr[i] && arr[i]>arr[i+1]){
                peaks.add(i);
            }
        }
        int maxi = 0;
        for(int i:peaks){
            int sum = arr[i];
            int j = i-1;
            while(j>=0 && arr[j]<arr[j+1]){
                sum+=arr[j];
                j--;
            }
            int k = i+1;

            while(k<n && arr[k-1]>arr[k]){
                sum+=arr[k];
                k++;
            }

            int len = k-j-1;

            if(len>=3){
                maxi = Math.max(maxi,sum);
            }
        }

        System.out.println(maxi);
    }
}
