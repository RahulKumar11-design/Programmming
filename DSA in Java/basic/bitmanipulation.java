package basic;
public class bitmanipulation {
    public static void getithbit(int n,int i){
        int bitmask = 1<<i;
        if((n & bitmask)==0){
            System.out.println("0");
        }else{
            System.out.println("1");
        }

    }
    public static int setithbit(int n,int i){
        int bitmask =1<<i;
        return (n | bitmask);
    }
    public static int clearithbit(int n,int i){
        int bitmask = ~(1<<i);
        return (n & bitmask);
    }
    public static int updateIthBit(int n,int i,int newBit){
        int bitmask = newBit<<i;
        return (clearithbit(n,i) | bitmask);

    }
    public static int clear_i_lastBit(int n,int i){
        int bitmask = (~0)<<i;
        return n&bitmask;

    }
    public static int ClearRangeBit(int n,int i,int j){
        int a = (-1)<<(j+1);
        int b = 1<<i -1;
        int bitmask = a|b;
        return n&bitmask;
    }
    public static Boolean isPowerof2(int n){
        if((n&(n-1))==0){
            return true;
        }
        else{
            return false;
        }
    }
    public static int SetBits(int n){
        int count=0;
        while(n>0){
            if((n&1) !=0){
                count++;
            }
            n=n>>1;
        
        }
        return count;
    }
    public static int FastExponentiation(int a,int n){
        int ans =1;
        while(n>0){
            if((n&1) !=0){
                ans = ans*a;
            }
            a=a*a;
            n=n>>1;
        }
        return ans;
    }
    public static int tFone(int arr[]){
        int result=0;
        for(int i=0;i<arr.length;i++){
            result=result^arr[i];
        }
        return result;
    }
    public static int minbitflip(int st,int en){
        int n = st^en;
        int count =0;
        while(n>0){
            n= n&(n-1);
            count++;
        }
        return count;
    }
    public static void main(String args[]){
        
    } 
}
