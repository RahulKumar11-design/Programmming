package advDS.tree;

public class TrieB {
    static class Node{
        Node children[] = new Node[26];
        boolean eow = false;
        int freq;
        public Node(){
            for(int i=0;i<children.length;i++){
                children[i] = null;
            }
            freq = 1;
        }
    }
    public static Node root = new Node();

    public static void insert(String word){   //O(L)
        Node curr = root;
        for(int level=0;level<word.length();level++){
            int idx = word.charAt(level) - 'a';
            if(curr.children[idx] == null){
                curr.children[idx] = new Node();
            }else{
                curr.children[idx].freq++;
            }
            curr = curr.children[idx];
        }

        curr.eow = true;
    }

    public static boolean search(String key){  //O(L)
        Node curr = root;
        for(int level=0;level<key.length();level++){
            int idx = key.charAt(level) - 'a';
            if(curr.children[idx] == null){
                return false;
            }
            curr = curr.children[idx];
        }

        return curr.eow == true;
    }
    public static boolean wordBreak(String key){//O(L)
        //base
        if(key.length()==0){
            return true;
        }
        //breaking into sub problems
        for(int i=1;i<=key.length();i++){
            if(search(key.substring(0,i)) 
            && wordBreak(key.substring(i))){
                return true;
            }
        }

        return false;
    }
    public static void findPrefix(Node root,String ans){
        if(root==null){
            return;
        }
        if(root.freq == 1){
            System.out.println(ans);
            return;
        }

        for(int i=0;i<root.children.length;i++){
            if(root.children[i]!=null){
                findPrefix(root.children[i], ans+(char)(i+'a'));
            }
        }
    }
    public static boolean startsWithProblem(String prefix){
        Node curr = root;
        for(int level=0;level<prefix.length();level++){
            int idx = prefix.charAt(level) - 'a';
            if(curr.children[idx]==null){
                return false;
            }
            curr = curr.children[idx];
        }
        return true;
    }
    public static int countNodes(Node root){
        if(root==null) return 0;
        int count = 0;
        for(int i=0;i<root.children.length;i++){
            if(root.children[i]!=null){
                count+=countNodes(root.children[i]);
            }
        }
        return count+1;
    }
    public static void find_unique_substring(String s){
        //find all suffix & insert them in trie
        for(int i=0;i<s.length();i++){
            insert(s.substring(i));
        }
        System.out.println("No. of unique substring of "+s+" is "+countNodes(root));
    }
    static String ans="";
    public static void longestWord(Node root,StringBuilder temp){
        if(root==null) return;
        for(int i=0;i<root.children.length;i++){
            if(root.children[i]!=null && root.children[i].eow){
                temp.append((char)(i+'a'));
                if(temp.length()>ans.length()){
                    ans = temp.toString();
                }
                longestWord(root.children[i], temp);
                //backtrack
                //temp = new StringBuilder(temp.substring(0, temp.length()-1)); 
                temp.deleteCharAt(temp.length()-1);
            }
        }
    }

    public static void main(String args[]){
        String words[] = {"a","ababa","aba","aa"};
        Solution s = new Solution();
        int n = s.countPrefixSuffixPairs(words);
        System.out.println(n);
    }
}
//java TrieB.java
class Solution{
    class prefix{
        prefix child[]=new prefix[26];
        boolean eow;
        int freq=0;
    }
    class suffix{
        suffix child[]=new suffix[26];
        boolean eow;
        int freq=0;
    }
    prefix root1 = new prefix();
    suffix root2 = new suffix();
    public void insert1(String word){
        prefix curr = root1;
        for(int i=0;i<word.length();i++){
            int idx = word.charAt(i)-'a';
            if(curr.child[idx]==null){
                curr.child[idx] = new prefix();
            }else{
                curr.child[idx].freq++;
            }
            curr = curr.child[idx];
        }
        curr.eow=true;
    }
    public void insert2(String word){
        suffix curr = root2;
        for(int i=word.length()-1;i>=0;i--){
            int idx = word.charAt(i)-'a';
            if(curr.child[idx]==null){
                curr.child[idx] = new suffix();
            }else{
                curr.child[idx].freq++;
            }
            curr = curr.child[idx];
        }
        curr.eow=true;
    }
    public boolean isPrefix(String key,int freq[]){
        prefix curr = root1;
        for(int i=0;i<key.length();i++){
            int idx = key.charAt(i)-'a';
            if(curr.child[idx]==null){
                return false;
            }
            curr = curr.child[idx];
        }
        freq[0] = curr.freq;
        return true;
    }
    public boolean isSuffix(String key,int freq[]){
        suffix curr = root2;
        for(int i=key.length()-1;i>=0;i--){
            int idx = key.charAt(i)-'a';
            if(curr.child[idx]==null){
                return false;
            }
            curr = curr.child[idx];
        }
        freq[0] = curr.freq;
        return true;
    }
    public int countPrefixSuffixPairs(String[] words) {
        for(int i=0;i<words.length;i++){
            insert1(words[i]);//prefix Trie
            insert2(words[i]);//suffix Trie
        }
        int count = 0;
        for(int i=0;i<words.length;i++){ 
            //check
            int freq1[]={0};int freq2[]={0};
            if(isPrefix(words[i],freq1) && isSuffix(words[i],freq2)){
                count+=Math.min(freq1[0],freq2[0]);
            }
        }
        return count;
    }
}
