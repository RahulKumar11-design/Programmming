package basic;
public class ArraysCC {
    public static int Linear_Search(int numbers[] ,int key){
        for(int i=1;i<numbers.length;i++){
            if(numbers[i]==key){
                return i;
            }

        }
        return -1;
    }
    public static int Linear_Search(String fruits[] ,String key){
        for(int i=0;i<fruits.length;i++){
            if(fruits[i]==key){
                return i;
            }

        }
        return -1;
    }
    public static int Largest(int numb[]){
        int largest = Integer.MIN_VALUE; // -infinity
        for(int i =0;i<numb.length;i++){
            if(numb[i] > largest){
                largest = numb[i];
            }

        }
        return largest;
    }
    public static int BinarySearch(int numb[], int key){
        int start = 0; int end = numb.length - 1;
        while(start<=end){
            int mid = (start+end)/2;
            // comparisons
            if(numb[mid] == key){  //found
                return mid;
            }
            else if(numb[mid]>key){ // left half
                end = mid-1;
            }
            else{                   // right half
                start = mid +1;
            }
            
        }
        return -1;
    }
    public static void reverse(int numb[]){
        int start =0;
        int end = numb.length - 1;
        //swap
        while(start<end){
            int temp = numb[start];
            numb[start] = numb[end];
            numb[end] = temp;
            start++; end--;
        }
    }
    public static void pairs(int numb[]){
        for(int i=0; i< numb.length;i++){
            //inner loop
            for(int j=i+1;j<numb.length;j++){
                System.out.print("("+numb[i]+","+numb[j]+")"+"  ");
            }
            System.out.println();
        }
    }
    
    public static void prefixSum(int numb[]){
        int currsum = 0;
        int largest = Integer.MIN_VALUE;
        int prefix[] = new int[numb.length];
        prefix[0] = numb[0];
        // calculate prefix
        for(int i=1;i<prefix.length;i++){
            prefix[i] = prefix[i-1]+numb[i];
        }


        for(int i=0;i<numb.length;i++){
            int start =i;
            for(int j=i;j<numb.length;j++){
                int end = j;
                currsum=0;
                currsum= (start==0)? prefix[end]: prefix[end]- prefix[start-1];
                if(currsum>largest){
                    largest=currsum;
                }
            }
        }
        System.out.println("largest sum of sub arrays = "+ largest);
        
    }
    public static void kadanes(int numb[]){
        int ms = Integer.MIN_VALUE;
        int sum = 0;
        for(int i=0;i<numb.length;i++){
            sum += numb[i];
            if(sum<0){
                sum=0;
            }
            if(ms<sum){
                ms =sum;
            }
        }System.out.println(sum);
    }
public static int trappedwater(int height[]){
        int trappedwater =0;
        //left max height
        int leftMax [] = new int[height.length];
        leftMax[0] = height[0];
        for(int i=1;i<height.length;i++){
            leftMax[i] = Math.max(leftMax[i-1],height[i]);
        }
        //right max height
        int rightMax[] = new int[height.length];
        rightMax[height.length -1] =height[height.length -1];
        for(int i=height.length-2; i>=0;i--){
            rightMax[i]=Math.max(rightMax[i+1],height[i]);
        }
        //loop
        for(int i=0;i<height.length;i++){
            int waterLevel = Math.min(leftMax[i],rightMax[i]); //water level = min(maxleft,max right)
            trappedwater += waterLevel -height[i];             
        } 
        return trappedwater;
       
    }

    public static int buyAndSellStocks(int prises[]){
        int minbuyprices = Integer.MAX_VALUE;
        int maxprofit =0;
        for(int i=0;i<prises.length;i++){
            if(minbuyprices<prises[i]){        // prises[i] =selling prises
                int profit = prises[i] -minbuyprices;
                maxprofit =Math.max(maxprofit, profit);  

            }
            else{
                minbuyprices =prises[i];
            }
        }
        return maxprofit;
    }
    public static void pascal(int n){
        int arr[] = {1};
        for(int level=2;level<=n;level++){
            for(int i=0;i<arr.length;i++){
                System.out.print(arr[i]+" ");
            }System.out.println();
            int oldarr[] = arr;
            arr = new int[level];
            int k=0;
            for(int j=-1;j<oldarr.length;j++){
                if(j==-1){
                    arr[k++]=oldarr[j+1];
                }else if(j==oldarr.length-1){
                    arr[k++]=oldarr[j];
                }else{
                    arr[k++]=oldarr[j]+oldarr[j+1];
                }
            }
        }
    }
    public static void main(String[] args) {
        // Scanner sc = new Scanner(System.in);
        // int n = sc.nextInt();
        // pascal(n);
        
    }
}           