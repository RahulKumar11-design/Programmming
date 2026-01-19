import transport.vehicle;
public class check {
    class car extends vehicle{
        public car(){
            // this.mirror=2;
            // can't acess default modifier in subclass outside the package *
            this.tyres=4;
            this.doors=3;
            //public and protected allow
        }
    }
    public static void main(String[] args) {
        vehicle v = new vehicle();
        // v.tyres=7;
        // can't acess protected modifier outside the package *

        v.doors=2;//only public allow outside the package
    }
}
