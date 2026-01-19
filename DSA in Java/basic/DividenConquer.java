package basic;
 public class DividenConquer{
    public static void printarr(int arr[]){
        for(int i=0;i<arr.length;i++){
            System.out.print(arr[i]+" ");
        }System.out.println();
    }
    public static void mergeSort(int arr[],int si,int ei){
        if(si>=ei){
            return;
        }
        int mid = si + (ei-si)/2;
        mergeSort(arr, si, mid);      //left array
        mergeSort(arr, mid +1, ei);   //right array
        merge(arr,si,mid,ei);
    }
    public static void merge(int arr[],int si,int mid,int ei){
        int temp[] = new int[ei-si+1];
        int i = si;//iteration for left array
        int j =mid+1;//iteration for right array
        int k = 0;//iteration for temp array
        while(i<=mid && j<=ei){
            if(arr[i]<arr[j]){
                temp[k] = arr[i];
                i++;
            }else{
                temp[k] = arr[j];
                j++;
            }
            k++;
        }
        //for left part
        while(i<=mid){
            temp[k++]=arr[i++];
        }
        //for right part
        while(j<=ei){
            temp[k++]=arr[j++];
        }
        //copy temp in original arr
        for(k=0,i=si;k<temp.length;i++,k++){
            arr[i] = temp[k];
        }
    }
    public static void quicksort(int arr[],int si,int ei){
        if(si>=ei){
            return;
        }
        // last element
        int pIdx = partition(arr,si,ei);
        quicksort(arr, si, pIdx-1); //left part
        quicksort(arr, pIdx+1, ei);//right part
    }
    public static int partition(int arr[],int si,int ei){
        int pivot = arr[ei];
        //jagah badlne ke liye
        int i = si-1;
        for(int j=si;j<ei;j++){
            if(arr[j]<=pivot){
                i++;
                //swap
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp; 
            }
        }
        i++;
        int temp = pivot;
        arr[ei] = arr[i];
        arr[i] = temp;

        return i;
    }
    public static int searchMod(int arr[],int si,int ei,int target){
        if(si>ei){
            return -1;
        }
        int mid = si +(ei-si)/2;
        if(arr[mid]==target){
            return mid;
        }
        //mid on L1
        if(arr[si]<=arr[mid]){
            if(arr[si]<=target && target<=arr[mid]){
                return searchMod(arr, si, mid-1, target);
            }
            else{
                return searchMod(arr, mid+1, ei, target);
            }
        }else{
            if(arr[mid]<=target && target<=arr[ei]){
                return searchMod(arr, mid+1, ei, target);
            }else{
                return searchMod(arr, si, mid-1, target);
            }
        }
    }
    public static void main(String args[]){
        int arr[] = {4,5,6,7,0,1,2};
        int idx = searchMod(arr, 0, arr.length-1, 0);
        System.out.println(idx);
    }
}