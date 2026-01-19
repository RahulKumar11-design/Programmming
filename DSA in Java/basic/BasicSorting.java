package basic;
public class BasicSorting {
    public static void BubbleSort(int numb[]){
        for(int turn=0;turn<numb.length;turn++){
            boolean swap = false;
            for(int j=0;j<numb.length-1-turn;j++){
                if(numb[j]>numb[j+1]){
                    //swap
                    int temp = numb[j];
                    numb[j] =numb[j+1];
                    numb[j+1] = temp;

                    swap = true;
                }
            }
            if(swap==false){
                break;
            }
        }

    }

    public static void selectionsort(int Arr[]){
        for(int i=0;i<Arr.length-1;i++){
            int minPos = i;
            for(int j=i;j<Arr.length;j++){
                if(Arr[minPos]>Arr[j]){
                
                    minPos=j;

                }
            }
            //swap
            int temp = Arr[i];
            Arr[i] = Arr[minPos];
            Arr[minPos] =temp;            
        }
    }

    public static void insertionSort(int Arr[]){
        // find out correct position
        for(int i =1;i<Arr.length;i++){
            int curr = Arr[i];  int j=i;                   // temp
            int prev = i-1;
            while(prev>=0 && Arr[prev]>curr){
                Arr[prev+1] = Arr[prev];
                j=prev;
                prev--;

            }
            //insertion
            Arr[j] = curr;
        }
        
    }

    public static void Printsorted(int Arr[]){
        for(int i=0;i<Arr.length;i++){
            System.out.print(Arr[i]+" ");
        }
     System.out.println();   

    }

    public static void countSort(int Arr[]){
        // calculate range
        int largest = Integer.MIN_VALUE;
        for(int i = 0;i< Arr.length;i++){
            largest = Math.max(largest,Arr[i]);
        }
        //count
        int count[] = new int[largest+1];
        for(int i =0;i<Arr.length;i++){                 //
                count[Arr[i]]++;
        }
        
        
        //sorting
        int j=0;
        for(int i=0;i<count.length;i++){
            while(count[i]>0){
                Arr[j] = i;
                j++;
                count[i]--;                   ////////
            }
        }
    }


    public static void main(String[] args) {
        int Arr[] = {5,3,2,1,4};
        insertionSort(Arr);
        Printsorted(Arr);  
    }
    
}
