package basic;
import java.util.ArrayList;
import java.util.List;

public class RecursionBasics {
    public static void printDec(int n){
        if(n == 1){
            System.out.print(n);
            return;
        }
        System.out.print(n+" ");
        printDec(n-1);
    }
    public static void printInc(int n){
        if(n==1){
            System.out.print(n+" ");
            return;
        }
        printInc(n-1);
        System.out.print(n+" ");
    }
    public  static int factorial(int n){
        if(n==0){
            return 1;
        }
        int fnm1 = factorial(n-1);
        int fact = n*fnm1;
        return fact;
    }
    public static int sumNN(int n){
        if(n==1){
            return 1;
        }
        int snm1=sumNN(n-1);
        int sum = n+snm1;
        return sum;
    }
    public static int fibonacciN(int n){
        if(n==0||n==1){
            return n;
        }
        int fibNm2=fibonacciN(n-2);
        int fibNm1=fibonacciN(n-1);
        return fibNm1+fibNm2;
    }
    public static Boolean isSorted(int arr[],int i){
        if(i==arr.length-1){
            return true;
        }
        else if(arr[i]>arr[i+1]){
            return false;
        }
        return isSorted(arr, i+1);
    }
    public static int firstOccurence(int arr[],int key,int i){
        if(arr[i]==key){
            return i;
        }
        if(i==arr.length-1){
            return -1;//not available
        }
        return firstOccurence(arr, key, i+1);
    }
    public static int lastOccurence(int arr[],int key,int i){
        if(i==arr.length){
            return -1;
        }
        int isFound = lastOccurence(arr, key, i+1);
        if(isFound==-1 && arr[i]==key){
            return i;
        }
        return isFound;
    }
    public static int pow(int x,int n){
        if(n==1){
            return x;
        }
        return x*pow(x, n-1); 
    }
    public static int optimizedPower(int x,int n){
    if(n==0){
        return 1;
    }
    int halfPower=optimizedPower(x,n/2);
    int halfPowerSq= halfPower*halfPower;
    if(n%2 !=0){
        halfPowerSq=x*halfPowerSq;
    } 
    return halfPowerSq;
    }
    public static int tilingProblem(int n){ // floor 2*n
        //base
        if(n==0||n==1){
            return 1;
        }
        return friendsPairing(n-1)+friendsPairing(n-2);
    }
    public static void removeDuplicates(String str,int i,boolean map[],StringBuilder newstr){
        // base case
        if(i==str.length()){
            System.out.println(newstr);
            return;
        }
        //kaam
        char currChar = str.charAt(i);
        if(map[currChar-'a']==true){
            removeDuplicates(str, i+1, map, newstr);
        }
        else{
            map[currChar-'a']=true;
            removeDuplicates(str, i+1, map, newstr.append(currChar));
        }
    }
    public static int friendsPairing(int n){
        //base
        if(n==1||n==2){
            return n;
        }
        return friendsPairing(n-1)+(n-2)*friendsPairing(n-2) ; 
    }
    public static void printBinString(int n,String str,int lastplace){
        if(n==0){
            System.out.println(str);
            return;
        }
        //kaam
        printBinString(n-1, str+"0", 0);
        if(lastplace==0){
            printBinString(n-1, str+"1", 1);
        }
    }
    static ArrayList<String> list = new ArrayList<>();
    public static void binString(int n,String str,int lastplace){
        if(n==0){
            list.add(str);
            return;
        }
        binString(n-1,str+"1",1);
        if(lastplace==1){
           binString(n-1,str+"0",0);
        }
    }
    public static List<String> validStrings(int n) {
        binString(n,"",1);
        return list;
    }
    public static void main(String[] args) {
        System.out.println(validStrings(12));
    }
}
