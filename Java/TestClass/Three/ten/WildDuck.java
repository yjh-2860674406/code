package TestClass.Three.ten;

public class WildDuck implements Swimmable, Flyable{

    @Override
    public void fly() {
        System.out.println("鸭子正在飞！");
    }

    @Override
    public void swim() {
        System.out.println("鸭子正在游泳！");        
    }
    
    public static void main(String[] args) {
        WildDuck duck = new WildDuck();
        duck.fly(); duck.swim();
    }

}
