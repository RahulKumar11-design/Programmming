package basic;
import java.util.Scanner;

public class matrices {

    public static boolean Search(int matrix[][],int key){
        for(int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix[0].length;j++){
                if(matrix[i][j] == key){
                    System.out.print("index found at "+ "("+i+","+j+")");
                    return true;
                }
            }
        }
        System.out.println("not found");
        return false;
    }
    public static void print_Spiral(int matrix[][]){
        int startrow = 0;int endrow = matrix.length -1;
        int startcol =0; int endcol = matrix[0].length -1;
        while(startrow<=endrow && startcol<=endcol){
            //top
            for(int j=startcol;j<=endcol;j++){
                System.out.print(matrix[startrow][j]+" ");

            }
            //right
            for(int i=startrow+1;i<=endrow-1;i++){
                System.out.print(matrix[i][endcol]+" ");
            }
            //bottom
            for(int j=endcol;j>=startcol;j--){
                if(startrow==endrow){
                break;
                }
                System.out.print(matrix[endrow][j]+" ");
               
            }
            //left
            for(int i=endrow-1;i>=startrow+1;i--){
                System.out.print(matrix[i][startcol]+" ");
            }
            startcol++;
            startrow++;
            endcol--;
            endrow--;


        }

        
    }

    public static int diagonal(int matrix[][]){
        int sum =0;
        for(int i=0;i<matrix.length;i++){
            //primary diagonal
            sum+= matrix[i][i];
            //secondary diagonal
            if(i!=matrix.length-1-i){
                sum+= matrix[i][matrix.length-1-i];
            }
        }
        return sum;
    }
    public static void binarySearch(int matrix[][],int key){
        for(int i=0;i<matrix.length;i++){
            int start=0;int end =matrix.length-1;
            while(start<end){
                int mid =(start+end)/2;
                if(matrix[i][mid]==key){
                    System.out.println(i+","+mid);
                    break;

                }
                else if(matrix[i][mid]>key){
                    end =mid-1;
                }
                else{
                    start =mid+1;
                }

            }
        }

    }
    public static Boolean staircaseSearch(int matrix[][],int key){
        int row = matrix.length-1;
        int col = 0;
        while(row>=0 && col<matrix[0].length){
            if(matrix[row][col]==key){
                System.out.println("("+row+","+col+")");
                return true;
            }
            else if(matrix[row][col]<key){
                col++;
            }
            else{
                row--;
            }
        }
        System.out.println("not found");
        return false;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int matrix[][] = {
            {1,2,3},
            {4,5,6},
            {7,8,9},
            {10,11,12}};
            print_Spiral(matrix);

        sc.close();
    }
}
