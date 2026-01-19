package transport;

public class vehicle{
    private String type;
    int mirror;//default
    protected int tyres;
    public int doors;
    public void show(){
        System.out.println("I am vehicle of "+type);
    }
    public void setType(String type){
        this.type = type;//private allow to use var inside that class
    }
}