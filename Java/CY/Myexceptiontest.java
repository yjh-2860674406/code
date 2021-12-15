package CY;
class  Iexception extends Exception{
    private String message;
    public Iexception(){}
    public Iexception(String message){
        super(message);
        this.message = message;
    }
    public void print(){
        System.out.println(message);
    }
}

public class Myexceptiontest {
    public static void main(String[] args) {
        try{
            Iexception iexception = new Iexception("自定义错误！");
            throw iexception;
        }catch(Iexception e){
            e.print();
        } 
    }      
}
