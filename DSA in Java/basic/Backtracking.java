package basic;
import java.util.*;

public class Backtracking {
    public static void findSubset(String str,StringBuilder ans,int i){
        // base
        if(i==str.length()){
            if(ans.length()==0){
                System.out.println("null");
            }else{
            System.out.println(ans);
            ans.delete(ans.length()-1, ans.length());
            }
            return;
        }
        //Recursion (kaam) -choices
        findSubset(str, ans.append(str.charAt(i)), i+1);
        //Backtracking
        findSubset(str, ans, i+1);
    }
    public static void findPermutations(String str,String ans){
        // Base
        if(str.length()==0){
            System.out.println(ans);
            return;
        }
        //kaam
        for(int i=0;i<str.length();i++){
            char curr = str.charAt(i);
            // "abcde" = "ab"+"de"
            String Newstr = str.substring(0, i) + str.substring(i+1);
            findPermutations(Newstr, ans+curr);
        }
    }
    public static void printmatrices(char matrix[][]){
        System.out.println("----chess-board-----");
        for(int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix[0].length;j++){
                System.out.print(matrix[i][j]+" ");
            }
            System.out.println();
        }
    }
    public static Boolean isSafechess(char board[][],int row,int col){
        // vertically up
        for(int i=row-1;i>=0;i--){
            if(board[i][col]=='Q'){
                return false;
            }
        }
        // diagonally up left
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        // diagonally up right
        for(int i=row-1,j=col+1;i>=0 && j<board[0].length;i--,j++){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }
    public static void nQueens(char board[][],int row){
        //base
        if(row==board.length){
            printmatrices(board);
            return;
        }
        //column loop
        for(int j=0;j<board.length;j++){
            if(isSafechess(board,row,j)){
                board[row][j]='Q';
                nQueens(board, row+1); //function call
                board[row][j]='x';    //backtracking
            }
        }
    }
    public static int gridWays(int i,int j,int n,int m){
        if(i==n-1 && j==m-1){  //reach target
            return 1;
        }else if(i==n || j==m){ //out of boundary
            return 0;
        }
        int w1 = gridWays(i+1, j, n, m); //down
        int w2 = gridWays(i, j+1, n, m); //right
        return w1 + w2;
    }
    public static void printmatrices(int matrix[][]){
        for(int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix[0].length;j++){
                System.out.print(matrix[i][j]+" ");
            }
            System.out.println();
        }
    }
    public static Boolean isSafesudoku(int sudoku[][],int row,int col,int digit){
        //col
        for(int i=0;i<=8;i++){
            if(sudoku[i][col]==digit){
                return false;
            }
        }     
        // row
        for(int j=0;j<=8;j++){
            if(sudoku[row][j]==digit){
                return false;
            }
        }  
        // grid
        int sr=(row/3)*3;
        int sc=(col/3)*3;
        for(int i=sr;i<sr+3;i++){
            for(int j=sc;j<sc+3;j++){
                if(sudoku[i][j]==digit){
                    return false;
                }
            }
        }
        return true;
    }
    public static Boolean sudokusolver(int sudoku[][],int row,int col){
        //Base
        if(row==9){
            return true;
        }
        //Recursion
        int nextCol= col+1;int nextRow= row;
        if(col+1 == 9){
            nextRow=row+1;
            nextCol=0;
        }
        if(sudoku[row][col]!=0){
            return sudokusolver(sudoku, nextRow, nextCol);
        }
        for(int digit=1;digit<=9;digit++){
            if(isSafesudoku(sudoku,row,col,digit)){
                sudoku[row][col]=digit;
                if(sudokusolver(sudoku, nextRow, nextCol)){
                    return true;
                }
                sudoku[row][col]=0;
            }
        }
        return false;
    }
    public static void SUDOKU(){
        int sudoku[][] = { {0,0,8,0,0,0,0,0,0},
        {4,9,0,1,5,7,0,0,2},
        {0,0,3,0,0,4,1,9,0},
        {1,8,5,0,6,0,0,2,0},
        {0,0,0,0,2,0,0,6,0},
        {9,6,0,4,0,5,3,0,0}, 
        {0,3,0,0,7,2,0,0,4},
        {0,4,0,0,3,0,0,5,7},
        {8,2,7,0,0,9,0,1,3}};
        if(sudokusolver(sudoku,0,0)){
            System.out.println("Solution does exist");
            printmatrices(sudoku);
        }else{
            System.out.println("Solution does not exist");
        }
    } 
    static String curr="";
    public static void ratInMaze(int maze[][],int i,int j,int n,String curr){
        if(i<0 || j<0 || i==n || j==n || maze[i][j]!=1){
            return;
        }
        if(i==n-1 && j==n-1){
            maze[i][j]=2;
            printmatrices(maze);
            System.out.println(curr);
        }
        maze[i][j]=2;        //block
        ratInMaze(maze, i, j+1, n, curr+'R');//right
        ratInMaze(maze, i+1, j, n, curr+'D');//down
        ratInMaze(maze, i-1, j, n, curr+'U');//up
        ratInMaze(maze, i, j-1, n, curr+'L');//left
        maze[i][j]=1;       //unblock
    }
    public static char A[][]={{},{},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},
                              {'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
    public static void keyPadCombination(char A[][],String str,int i,String curr){
        if(i==str.length()){
            System.out.println(curr);
            return;
        }
        char Letter[] = A[Character.getNumericValue(str.charAt(i))];
        for(int j=0;j<Letter.length;j++){
            keyPadCombination(A, str, i+1, curr+(Letter[j]));
        } 
    }     
    public static List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();

        if (nums.length == 1) {
            List<Integer> singleNum = new ArrayList<>();
            singleNum.add(nums[0]);
            res.add(singleNum);
            return res;
        }

        for (int i = 0; i < nums.length; i++) {
            int n = nums[i];
            int[] remainingNums = new int[nums.length - 1];
            int idx = 0;
            for (int j = 0; j < nums.length; j++) {
                if (j != i) {
                    remainingNums[idx++] = nums[j];
                }
            }
            List<List<Integer>> perms = permute(remainingNums);

            for (List<Integer> perm : perms) {
                perm.add(n);
                res.add(new ArrayList<>(perm));
            }
        }
        return res;
    }                        
    public static void main(String args[]){
        //keyPadCombination(A, "97", 0,"");
        // for(char digit='1';digit<='9';digit++){
        //     System.out.print(digit+"");
        // }
        //java Backtracking.java
        // int nums[] = {1,2,3};
        // System.out.println(permute(nums));  
          
    }
}
