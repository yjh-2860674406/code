package Java.book10;

public class Duck implements Swimmable, Flyable {

    @Override
    public void fly() {
        System.out.println("鸭子正在飞！");
    }

    @Override
    public void swim() {
        System.out.println("鸭子正在游泳！");
    }
    
    public static void main(String[] args) {
        Duck duck = new Duck();
        duck.swim(); duck.fly();
    }
}
