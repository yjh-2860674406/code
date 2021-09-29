package Java.cy.auto;

public class Bus extends Auto{
    private int passenger = 0;
    public Bus(int num){
        super();
        this.passenger = num; 
    }
    public void gotOn(int num){
        System.out.println("乘客在上车！");
        this.passenger += num;
    }
    public void gotOff(int num){
        this.stop();
        System.out.println("乘客在下车！");
        this.passenger -= num;
    }

    public static void main(String[] args) {
        Bus bus_1 = new Bus(10);
        bus_1.start();
        bus_1.speedUp();
        bus_1.gotOn(10000);
        bus_1.gotOff(100);
        
    }
}
