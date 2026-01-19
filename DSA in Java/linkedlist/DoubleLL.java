package linkedlist;
class Node{
    int data;
    Node next;
    Node prev;
    public Node(int data){
        this.data=data;
        this.next=null;
        this.prev=null;
    }
}
public class DoubleLL {
    public Node head;
    public Node tail;
    public int size;
    public void addFirst(int data){
        Node newNode = new Node(data);
        size++;
        if(head==null){
            head=tail=newNode;
            return;
        }
        newNode.next = head;
        head.prev=newNode;
        head=newNode;
    }
    public void addLast(int data){
        Node newNode = new Node(data);
        size++;
        if(head==null){
            head=tail=newNode;
            return;
        }
        tail.next=newNode;
        newNode.prev=tail;
        newNode.next=null;
        tail=newNode;
    }
    public void print(){
        Node temp = head;
        while(temp!=null){
            System.out.print(temp.data+"<->");
            temp=temp.next;
        }System.out.println("null");
    }
    public int removeFirst(){
        if(head==null){
            return Integer.MIN_VALUE;
        }
        if(size==1){
            int val=head.data;
            head=tail=null;
            size--;
            return val;
        }
        int val=head.data;
        head=head.next;
        head.prev=null;
        size--;
        return val;
    }
    public int removeLast(){
        if(head==null){
            return Integer.MIN_VALUE;
        }
        if(size==1){
            int val = head.data;
            head=tail=null;
            size--;
            return val;
        }
        int val = tail.data;
        tail = tail.prev;
        tail.next=null;
        size--;
        return val;
    }
    public void reverse(){
        Node curr=head;
        Node prev=null;
        Node next;
        while(curr!=null){
            next=curr.next;
            curr.next=prev;
            curr.prev=next;

            prev=curr;
            curr=next;
        }
        head=prev;
    }
}
