package advDS;
import java.util.*;

public class StackB {
    public static void pushAtBottom(Stack<Integer> s,int data){
        //base
        if(s.empty()){
            s.push(data);
            return;
        }
        //kaam
        int top=s.pop();
        pushAtBottom(s, data);
        s.push(top);
    }
    public static String reverseString(String str){
        Stack<Character> s = new Stack<>();
        int idx=0;
        while(idx<str.length()){
            s.push(str.charAt(idx));
            idx++;
        }
        StringBuilder sb = new StringBuilder();
        while(!s.empty()){
            sb.append(s.pop());
        }
        return sb.toString();
    }
    public static void reverseStack(Stack<Integer> s){
        //base
        if(s.empty()){
            return;
        }
        //kaam
        int top=s.pop();
        reverseStack(s);
        pushAtBottom(s, top);
    }
    public static void printStack(Stack<Integer> s){
        while(!s.empty()){
            System.out.println(s.pop());
        }
    }
    public static void stocksSpan(int Stocks[],int Span[]){
        Stack<Integer> s = new Stack<>();
        s.push(0);
        Span[0]=1;
        for(int i=1;i<Span.length;i++){
            int curr = Stocks[i];
            while(!s.empty() && curr>=Stocks[s.peek()]){
                s.pop();
            }
            if(s.empty()){
                Span[i]=i+1;
            }else{
                int prevHigh = s.peek();
                Span[i]=i-prevHigh;
            }
            s.push(i);
        } 
    }
    public static void printarr(int arr[]){
        for(int i=0;i<arr.length;i++){
            System.out.print(arr[i]+" ");
        }
    }
    public static void nextGreaterRight(int arr[],int nxtGtr[]){
        Stack<Integer> s = new Stack<>();
        for(int i=arr.length-1;i>=0;i--){
            while(!s.empty() && arr[s.peek()]<=arr[i]){
                s.pop();
            }
            if(s.empty()){
                nxtGtr[i]=-1;
            }else{
                nxtGtr[i]=arr[s.peek()];
            }
            s.push(i);
        }
    }
    public static boolean isValid(String s){
        if(s.length()%2!=0){
            return false;
        }
        Stack<Character> stack = new Stack<>();
        for(Character c : s.toCharArray()){
            if(c=='(' || c=='{' || c=='['){
                stack.push(c);
            }
            else if(c==')'){
                char top = stack.peek();
                if(top=='(' && !stack.empty()){
                    stack.pop();
                }else{
                    return false;
                }
            }
            else if(c=='}'){
                char top = stack.peek();
                if(top=='{' && !stack.empty()){
                    stack.pop();
                }else{
                    return false;
                }
            }
            else if(c==']'){
                char top = stack.peek();
                if(top=='[' && !stack.empty()){
                    stack.pop();
                }else{
                    return false;
                }
            }
        }
        return stack.empty();
    }
    public static String simplifyPath(String path){
        String arr[]=path.split("/");String result ="/";
        Stack<String> stack = new Stack<>();int i=0;
        for(String s:arr){
            if(s.equals("..")){
                if(!stack.empty()){
                    stack.pop();
                }else{
                    continue;
                }
            }else if(s.equals(".") || s.isEmpty()){
                continue;
            }else{
                stack.push(s);
            }
        }
        while(!stack.empty()){
            arr[i++]=stack.pop();
        }
        for(int j=i-1;j>=0;j--){
            if(j!=0){
                result=result+arr[j]+"/";
            }else{
                result=result+arr[j];
            }
        }
        return result;
    }
    public static boolean isDuplicate(String str){
        Stack<Character> stack = new Stack<>();
        for(Character c:str.toCharArray()){
            //opening->push
            if(c!=')'){
                stack.push(c);
            }
            //closing
            else{
                int count=0;
                while(stack.pop()!='('){
                    count++;
                }
                if(count<1){
                    return true;
                }
            }
        }
        return false;
    }
    public static void nextSmallerLeft(int arr[],int nxtSml[]){
        Stack<Integer> s = new Stack<>();//index
        for(int i=0;i<arr.length;i++){
            while(!s.empty() && arr[s.peek()]>=arr[i]){
                s.pop();
                }
            if(s.empty()){
                nxtSml[i]=-1;
            }else{
                nxtSml[i]=s.peek();
            }
            s.push(i);
        }
    }
    public static void nextSmallerRight(int arr[],int nxtSml[]){
        Stack<Integer> s = new Stack<>();//index
        for(int i=arr.length-1;i>=0;i--){
            while(!s.empty() && arr[s.peek()]>=arr[i]){
                s.pop();
                }
            if(s.empty()){
                nxtSml[i]=arr.length;
            }else{
                nxtSml[i]=s.peek();
            }
            s.push(i);
        }
    }
    public static int maxArea(int heights[]){  //O(n)
        int maxArea=0;

        int NS_left[] = new int[heights.length];
        nextSmallerLeft(heights, NS_left);

        int NS_right[] = new int[heights.length];
        nextSmallerRight(heights, NS_right);

        for(int k=0;k<heights.length;k++){
            //hgt
            int hgt=heights[k];
            //wdt
            int i = NS_left[k];
            int j = NS_right[k];
            int wdt = j-i-1;
            //area=hgt*wdt
            int area = hgt*wdt;
            maxArea=Math.max(area,maxArea);
        }
        return maxArea;
    }
    public static void main(String[] args) {
        //java StackB.java
        //int heights[] = {2,1,5,6,2,3};
        //System.out.println(maxArea(heights));
        System.out.println(simplifyPath("/sd/ss/.././//.../"));
    }
}
