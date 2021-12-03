package Book.book10;

public class book10_Duck implements book10_Swimmable, book10_Flyable {

    @Override
    public void fly() {
        System.out.println("鸭子正在飞！");
    }

    @Override
    public void swim() {
        System.out.println("鸭子正在游泳！");
    }
    public static void main(String[] args) {
        book10_Duck duck = new book10_Duck();
        duck.swim(); duck.fly();
    }
}
