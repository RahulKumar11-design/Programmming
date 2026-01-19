import java.util.Stack;
class Expression{
    public static int pref(char c){
        if(c=='^') return 3;
        else if(c=='*' || c=='/') return 2;
        else if(c=='+' || c=='-') return 1;
        else return 0;
    }
    public static String infixToPostfix(String s) {
        StringBuilder sb = new StringBuilder();
        Stack<Character> st = new Stack<>();
        
        for(Character symb:s.toCharArray()){
            if(('a'<=symb && symb<='z') || ('A'<=symb && symb<='Z') || ('0'<=symb && symb<='9')){
                sb.append(symb);
            }else if(symb=='('){
                
                st.push(symb);
            }else if(symb==')'){
                
                while(!st.isEmpty() && st.peek()!='('){
                    sb.append(st.pop());
                }
                
                if(!st.isEmpty()) st.pop();//'('
            }else{
                while(!st.isEmpty() && pref(st.peek())>=pref(symb)){
                    // equal for left associative
                    // a+b+c -> ab+c+
                    if(st.peek()=='^' && symb=='^') break;
                    //a^b^c -> a^(b^c) -> abc^^
                    sb.append(st.pop());
                }
                st.push(symb);
            }
            // System.out.println(st);
        }
        while(!st.isEmpty()){
            sb.append(st.pop());//add the rest symb
        }
        return sb.toString();
    }
    public static void main(String[] args) {
        System.out.println(infixToPostfix("a+b*(c^d-e)^(f+g*h)-i"));
    }
}