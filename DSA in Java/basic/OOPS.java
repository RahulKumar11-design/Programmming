package basic;
import java.util.*;
class OOPS {
    static class Complex{
        int real;
        int imag;
        Complex(int r,int i){
            real =r;imag=i;
        }
        public Complex add(Complex a,Complex b){
            Complex c = new Complex(0,0);
            c.real = a.real+b.real;c.imag = a.imag + b.imag;
            return c;
        }
        public Complex diff(Complex a,Complex b){
            Complex c = new Complex(0,0);
            c.real = a.real-b.real;c.imag = a.imag-b.imag;
            return c;
        }
        public Complex prod(Complex a,Complex b){
            Complex c = new Complex(0,0);
            c.real = a.real*b.real - a.imag*b.imag ;c.imag =a.real*b.imag+a.imag*b.real ;
            return c;
        }
        public void print(Complex c){
            if(c.imag==0){
                System.out.println(c.real);
            }
            else if(c.real==0){
                System.out.println(c.imag+"i");
            }
            else{
                if(c.imag>0){
                System.out.println(c.real+"+"+c.imag+"i");
                }else{
                    System.out.println(c.real+""+c.imag+"i");//
                }
            }
        }
    }
    class QueueC{
        static Stack<Integer> s1 = new Stack<>();
        static Stack<Integer> s2 = new Stack<>();
        public static boolean isEmpty(){
            System.out.println("queue is empty");
            return s1.empty();
        }
        public static void add(int data){  //O(n)
            if(!isEmpty()){
                while(!s1.empty()){
                    s2.push(s1.pop());
                }
                s1.push(data);
                while(!s2.empty()){
                    s1.push(s2.pop());
                }
                return;
            }
            s1.push(data);
        }
        public static int remove(){
            if(isEmpty()){
                return -1;
            }
            return s1.pop();
        }
        public static int peek(){
            if(isEmpty()){
                return -1;
            }
            return s1.peek();
        }
    }
    class StackR{
        static Queue<Integer> q1 = new LinkedList<>();
        static Queue<Integer> q2 = new LinkedList<>();
        public static boolean isEmpty(){
            return q1.isEmpty() && q2.isEmpty();
        }
        public static void push(int data){
            if(!q1.isEmpty()){
                q1.add(data);
                return;
            }else{
                q2.add(data);
            }
        }
        public static int pop(){   //O(n)
            if(isEmpty()){
                System.out.println("stack is empty");
                return -1;
            }
            int top=-1;
            if(!q1.isEmpty()){//case1
                while(!q1.isEmpty()){
                    top=q1.remove();
                    if(q1.isEmpty()){
                        break;
                    }
                    q2.add(top);
                }
            }else{           //case2
                while(!q2.isEmpty()){
                    top=q2.remove();
                    if(q2.isEmpty()){
                        break;
                    }
                    q1.add(top);
                }
            }
            return top;
        }
        public static int peek(){
            if(isEmpty()){
                System.out.println("stack is empty");
                return -1;
            }
            int top=-1;
            if(!q1.isEmpty()){//case1
                while(!q1.isEmpty()){
                    top=q1.remove();
                    q2.add(top);
                }
            }else{            //case2
                while(!q2.isEmpty()){
                    top=q2.remove();
                    q1.add(top);
                }
            }
            return top;
        }
    }
    class HeapB{
        ArrayList<Integer> arr = new ArrayList<>();
        public void add(int data){
            arr.add(data);  //O(1)
    
            int x = arr.size()-1; //child idx
            int par = (x-1)/2;    //parent idx
            //swap
            while(arr.get(x)<arr.get(par)){  //O(log(n))
                int temp = arr.get(x);
                arr.set(x,arr.get(par));
                arr.set(par,temp);
                //update
                x = par;
                par = (x-1)/2;
            }
        }
        public int peek(){
            return arr.get(0);
        }
        private void heapify(int i){
            int left = 2*i+1;
            int right = 2*i+2;
            int minIdx = i;
            if(left<arr.size() && arr.get(minIdx)>arr.get(left)){
                minIdx = left;
            }
            if(right<arr.size() && arr.get(minIdx)>arr.get(right)){
                minIdx = right;
            }
    
            if(minIdx!=i){
                //swap
                int temp = arr.get(minIdx);
                arr.set(minIdx,arr.get(i));
                arr.set(i,temp);
                
                heapify(minIdx);
            }
        }
        public int remove(){
            int data = arr.get(0);
            // swap 1st and last
            int temp = arr.get(0);
            arr.set(0,arr.get(arr.size()-1));
            arr.set(arr.size()-1,temp);
            // delete last
            arr.remove(arr.size()-1);
            //fix the heap
            heapify(0);
            return data;
        }
        public boolean isEmpty(){
            return arr.size()==0;
        }
    }
    class LRUCache {
        class Node {
            int key;
            int value;
            Node next;
            Node prev;
            Node(int key,int value){
                this.key=key;
                this.value=value;
            }
        }
        int N;
        //MRU
        Node head;
        //LRU
        Node tail;
        //map->(key,node containing key)
        HashMap<Integer,Node> map;
        public LRUCache(int capacity) {
            this.N=capacity;
            this.head = new Node(-1,-1);
            this.tail = head.next = new Node(-1,-1);
            tail.prev = head;
            this.map = new HashMap<>();
        }
        
        public void remove(Node curr){
            Node prev = curr.prev;
            prev.next = curr.next;
            curr.next.prev = prev; 
        }
    
        public void insert(Node curr){
            Node next = head.next;
            head.next = curr;
            curr.prev = head;
            
            curr.next = next;
            next.prev = curr;
        }
    
        public int get(int key) {
            if(map.containsKey(key)){
                Node node = map.get(key);
                //update
                remove(node);
                insert(node);
                return node.value;
            }
            return -1;
        }
        public void put(int key, int value) {
            if(map.containsKey(key)){
                Node node = map.get(key);
                node.value = value;
                //update
                remove(node);
                insert(node);
                map.put(key,node);
                return;
            }
            if(map.size()==N){
                //delete LRU
                Node lru = tail.prev;
                map.remove(lru.key);
                remove(lru);
            }
            Node newNode = new Node(key,value);
            map.put(key,newNode);
            insert(newNode);
        }
    }
    static class CircleQueue{
        static int arr[];
        static int size;
        static int rear;
        static int front;
        CircleQueue(int n){
            arr=new int[n];
            size=n;
            rear=-1;
            front=-1;
        }
        public boolean isEmpty(){
            return rear==-1 && front==-1;
        }
        public boolean isFull(){
            return (rear+1)%size==front;
        }
        public void add(int data){
            if(isFull()){
                System.out.println("queue is full");
                return;
            }
            if(front==-1){
                front=0;
            }
            rear=(rear+1)%size;
            arr[rear]=data;
        }
        public int remove(){
            if(isEmpty()){
                System.out.println("queue is empty");
                return -1;
            }
            int result=arr[front];
            if(front==rear){
                front=rear=-1;
            }else{
                front=(front+1)%size;
            }
            return result;
        }
        public int peek(){
            if(isEmpty()){
                System.out.println("queue is empty");
                return -1;
            }
            return arr[front];
        }
    }
    public static void main(String args[]){
        CircleQueue q = new CircleQueue(5);
        for(int i=1;i<6;i++){
            q.add(i);
        }
        while(!q.isEmpty()){
            System.out.print(q.remove()+" ");
        }
    }
}
//java OOPS.java
