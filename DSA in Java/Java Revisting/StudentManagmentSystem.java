import java.util.*;

class Student implements Comparable<Student>{
    int id;
    int marks;
    String name;
    public Student(int id,int marks,String name){
        this.id = id;
        this.marks = marks;
        this.name = name;
    }

    public int compareTo(Student s2){
        if(this.marks<s2.marks){
            return -1;
        }else{
            return 1;
        }
    }

    public String toString(){
        return this.id + " " + this.name;
    }
}

public class StudentManagmentSystem {
    ArrayList<Student> list = new ArrayList<>();
    HashMap<Integer,Integer> mp = new HashMap<>();

    void insert(String name,int id, int marks){
        list.add(new Student(id, marks, name));
        mp.put(id,list.size()-1);
    }

    void print(){
        for(Student st:list){
            if(st.marks>80) System.out.println(st.toString());
        }
    }

    public void sortBasedOnMarks(){
        Collections.sort(list);
    }

    public void sortBasedOnString(){
        Comparator<Student> cmp = new Comparator<Student>(){
            @Override 
            public int compare(Student s1,Student s2){
                return s1.name.compareTo(s2.name);
            }
        };

        Collections.sort(list, cmp);
    }

    public Student topper(){
        Student top = null;

        for(Student st:list){
            if(top==null){
                top = st;
            }else if(top.marks<st.marks){
                top = st;
            }
        }

        return top;
    }

    public float averageMarks(){
        float avg = 0;

        for(Student st:list){
            avg+=st.marks;
        }

        return avg/(list.size());
    }

    public Student search(int id){
        if(mp.containsKey(id)){
            return list.get(mp.get(id));
        }else{
            return null;
        }
    }

    public static void main(){
        StudentManagmentSystem sms = new StudentManagmentSystem();

        for(int i=0;i<8;i++){
            sms.insert("Helloo"+i,i+3,72+i);
        }
    }
    
}
