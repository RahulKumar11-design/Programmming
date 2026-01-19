package advDS;
import java.util.*;

public class HashMapCode {
    static class HashMap<K,V> {  // K,V -> generic
        private class Node {
            K key;
            V value;
            public Node(K key,V value){
                this.key=key;
                this.value=value;
            }
        }
        // size
        private int n;
        private int N; 
        private LinkedList<Node> buckets[];

        @SuppressWarnings("unchecked")
        public HashMap() {
            this.N=4;
            this.buckets = new LinkedList[4];
            for(int i=0;i<4;i++){
                this.buckets[i] = new LinkedList<>();
            }
        }
        @SuppressWarnings("unchecked")
        private void rehash(){
            LinkedList<Node> oldbucket[] = buckets;
            buckets = new LinkedList[2*N];
            N = 2*N;
            n=0;
            for(int i=0; i<buckets.length; i++){
                buckets[i] = new LinkedList<>();
            }
            // nodes in oldbucket -> add in bucket
            for(int i=0;i<oldbucket.length;i++){
                LinkedList<Node> ll = oldbucket[i];
                for(int j=0;j<ll.size();j++){
                    Node node = ll.remove();
                    put(node.key,node.value);
                }
            }
            
        }
        private int hashFunction(K key){
            int hc = key.hashCode();
            // -12131,1312
            return Math.abs(hc)%N;
        }

        private int SearchInLL(K key,int bi){
            LinkedList<Node> ll = buckets[bi];
            int di=0;

            for(int i=0;i<ll.size();i++){
                Node node = ll.get(i);
                if(node.key==key){
                    return di;
                }
                di++;
            }
            return -1; 
        }
        public void put(K key,V value){                    //O(lamda)->O(1)
            int bi = hashFunction(key); //index= 0 to 3
            int di = SearchInLL(key,bi);  // valid : -1

            if(di!=-1){
                Node node = buckets[bi].get(di);
                node.value=value;
            }else{
                buckets[bi].add(new Node(key,value));
                n++;
            }

            double lambda = (double)n/N;
            if(lambda>2.0){
                rehash();
            }
        }
        public boolean containsKey(K key){               //O(1)
            int bi = hashFunction(key); //index= 0 to 3
            int di = SearchInLL(key,bi);  // valid : -1

            if(di!=-1){
                return true;
            }else{
                return false;
            }
        }
        public V remove(K key){                      //O(1)
            int bi = hashFunction(key); //index= 0 to 3
            int di = SearchInLL(key,bi);  // valid : -1

            if(di!=-1){
                n--;
                Node node = buckets[bi].remove(di);
                return node.value;
            }else{
                return null;
            }
        }
        public V get(K key){                       //O(1)
            int bi = hashFunction(key); //index= 0 to 3
            int di = SearchInLL(key,bi);  // valid : -1

            if(di!=-1){
                Node node = buckets[bi].get(di);
                return node.value;
            }else{
                return null;
            }
        }
        public ArrayList<K> keySet() {
            ArrayList<K> keys = new ArrayList<>();
            for(int i=0;i<buckets.length;i++){
                LinkedList<Node> ll = buckets[i];
                for (Node node : ll) {
                    keys.add(node.key);
                }
            }
            return keys;
        }
        public boolean isEmpty(){
            return n==0;
        }
    }
    public static void main(String[] args) {
        HashMap<String,Integer> hm = new HashMap<>();
        hm.put("India", 100);
        hm.put("China",150);
        hm.put("US",50);
        hm.put("Nepal", 10);

        ArrayList<String> keys = hm.keySet();
        System.out.println(keys);
        System.out.println(hm.get("India"));
    }
}
//java HashMapCode.java