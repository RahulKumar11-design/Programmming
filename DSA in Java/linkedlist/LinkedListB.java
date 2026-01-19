package linkedlist;

public class LinkedListB {
    public static class Node{
        int data;
        Node next;
        public Node(int data){
            this.data = data;
            this.next = null;
        }
    }
    public static Node head;
    public static Node tail;
    public static int size;
    public void addFirst(int data){
        //create new node
        Node newNode =  new Node(data);
        size++;
        if(head==null){
            head = tail = newNode;
            return;
        }
        //link it to old head
        newNode.next = head;
        //make it head
        head = newNode;
    }
    public void addLast(int data){
        Node newNode = new Node(data);
        size++;
        if(head==null){
            head = tail = newNode;
            return;
        }
        tail.next = newNode;
        tail = newNode;
    }
    public void print(){  //O(n)
        if(head==null){
            System.out.println("LL is empty");
            return;
        }
        Node temp = head;
        while(temp!=null){
            System.out.print(temp.data+"->");
            temp = temp.next;
        }System.out.println("null");
    }
    public void add(int idx,int data){
        if(idx==0){
            addFirst(data);
            return;
        }
        Node newNode = new Node(data);
        size++;
        Node temp = head;
        int i=0;

        while(i<idx-1){
            temp = temp.next;
            i++;
        }
        //idx-1 -> prev
        newNode.next = temp.next;
        temp.next = newNode;
    }
    public int removeFirst(){
        if(size==0){
            System.out.println("LL is empty");
            return Integer.MIN_VALUE;
        }else if(size==1){
            int val = head.data;
            head = tail = null;
            size--;
            return val;
        }
        int val = head.data;
        head = head.next;
        size--;
        return val;
    }
    public int removeLast(){
        if(size==0){
            return Integer.MIN_VALUE;
        }else if(size==1){
            int val = head.data;
            head = tail =null;
            size=0;
            return val;
        }
        //prev i=>size-2
        Node prev = head;
        for(int i=0;i<size-2;i++){
            prev = prev.next;
        }
        int val = tail.data;
        prev.next = null;
        tail = prev; 
        size--;
        return val;
    }
    public int itrSearch(int key){   //O(n)
        Node temp = head;int i=0;
        while(temp!=null){
            if(temp.data == key){
                return i;
            }
            temp = temp.next;
            i++;
        }
        return -1;
    }
    public int helper(Node head,int key){
        if(head==null){
            return -1;
        }
        if(head.data == key){
            return 0;
        }
        int idx = helper(head.next, key);
        if(idx==-1){
            return -1;
        }
        idx = idx+1;
        return idx;
    }
    public int recSearch(int key){
        return helper(head,key);
    }
    public void reverse(){
        Node prev =null;
        Node curr=tail=head;
        Node next;
        
        while(curr!=null){
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr= next;
        }
        head = prev;
    }
    public void deleteNthfromEnd(int n){
        //size
        int sz = 0;
        Node temp = head;
        while(temp!=null){
            temp = temp.next;
            sz++;
        } 
        //n=sz
        if(n==sz){
            head = head.next; //remove first
            size--;
            return;
        }
        //sz-n
        int i=1;
        Node prev = head;
        while(i<sz-n){
            prev = prev.next;
            i++;
        }
        prev.next = prev.next.next;
        size--;
        return;
    }
    public Node findMid(Node head){
        Node slow = head;
        Node fast = head;
        while(fast!=null && fast.next!=null){
            slow = slow.next;//+1
            fast = fast.next.next;//+2
        }
        return slow;//slow is my mid
    }
    public Boolean checkPolindrome(){
        if(head==null || head.next==null){
            return true;
        }
        //step1:find mid
        Node midNode = findMid(head);
        
        //step2:reverse 2nd half
        Node prev = null;
        Node curr = midNode;
        while(curr!=null){
            Node next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }

        Node right = prev;
        Node left = head;
        //step3:check left and right
        while(right!=null){
            if(left.data != right.data){
                return false;
            }
            left = left.next;
            right = right.next;
        }
        
        return true;
    }
    public static Boolean iscycle(){
        Node slow = head;
        Node fast = head;
        while(fast!=null && fast.next!=null){
            slow = slow.next;
            fast = fast.next.next;
            if(slow==fast){
                return true;//cycle
            }
        }
        return false;
    }
    public static void removecycle(){
        //detect cycle
        Node slow = head;
        Node fast = head;
        Boolean cycle = false;
        while(fast!=null && fast.next!=null){
            slow = slow.next;
            fast = fast.next.next;
            if(slow==fast){
               cycle = true;
               break;
            }
        }
        if(cycle==false){
            return;
        }
        //find meeting cycle
        slow = head;
        Node last = null;
        while(slow!=fast){
            slow = slow.next;//+1
            last = fast;
            fast = fast.next;//+1
        }
        //remove cycle->last.next=null
        last.next = null;
    }
    public static Node getMid(Node head){
        Node slow = head;
        Node fast = head.next;//
        while(fast!=null && fast.next!=null){
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }
    public Node mergeSort(Node head){
        //base
        if(head==null || head.next==null){
            return head;
        }
        //mid
        Node mid = getMid(head);
        //left and right MS
        Node righthead = mid.next;
        mid.next = null;
        Node newleft = mergeSort(head);
        Node newright = mergeSort(righthead);
        //merge
        return merge(newleft,newright);
    }
    private Node merge(Node h1,Node h2){
        Node mergedLL = new Node(-1);
        Node temp = mergedLL;
        while(h1!=null && h2!=null){
            if(h1.data<=h2.data){
                temp.next = h1;
                h1 = h1.next;
            }else{
                temp.next = h2;
                h2 = h2.next;
            }
            temp = temp.next;
        }
        while(h1!=null){
            temp.next = h1;
            h1 = h1.next;
            temp = temp.next;
        }
        while(h2!=null){
            temp.next = h2;
            h2 = h2.next;
            temp = temp.next;
        }
        return mergedLL.next;
    }
    public void zigzagLL(){
        //mid
        Node slow = head;
        Node fast = head.next;
        while(fast!=null && fast.next!=null){
            slow=slow.next;
            fast=fast.next.next;
        }
        Node mid = slow;
        //2nd half reverse
        Node prev=null;
        Node curr=mid.next;
        mid.next=null;
        Node next;
        while(curr!=null){
            next=curr.next;
            curr.next=prev;
            prev=curr;
            curr=next;
        }
        //zig-zag
        Node Lhead=head;
        Node Rhead=prev;
        Node Lnext;Node Rnext;
        while(Lhead!=null && Rhead!=null){
            //zig-zag
            Lnext=Lhead.next;
            Lhead.next=Rhead;
            Rnext=Rhead.next;
            Rhead.next=Lnext;
            //update
            Lhead=Lnext;
            Rhead=Rnext;
        }
    }
    public void deleteN_after_M(int n,int m){
        Node dummyhead=head;Node temp1=head;Node temp2=head;
        while(dummyhead!=null && n>0){
            temp1=dummyhead;int i=1;
            while(i<m){
                temp1=temp1.next;
                i++;
            }
            dummyhead=temp1.next;
            temp2=dummyhead;i=1;
            while(i<n){
                temp2=temp2.next;
                i++;
            }
            //m->n+1
            temp1.next=temp2.next;
            temp2.next=null;
            size-=n;
            dummyhead=temp1.next;
        }
    }
    public static void main(String[] args){
        
        //java LinkedList.java
    }
}