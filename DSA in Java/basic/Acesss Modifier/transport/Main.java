package transport;
class Main{
    public static void main(String[] args) {
        vehicle v = new vehicle();
        // v.type = "land";
        //if private -> can't access within package *

        v.tyres = 4;// alowed by default and protected  and public within package
    }
}