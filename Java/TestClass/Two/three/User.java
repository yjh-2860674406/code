package TestClass.Two.three;

public class User {
    public static void main(String[] args) {
        Vehicle car = new Vehicle();
        System.out.println("现在速度为：" + car.getSpeed() + "，现在能量为：" + car.getPower());
        car.setPower(100);
        System.out.println("现在已充能，现在能量为：" + car.getPower());
        car.speedUp(40);
        System.out.println("现在加速至：" + car.getSpeed() + "，现在能量为：" + car.getPower());
        car.speedDowm(20);
        System.out.println("现在减速至：" + car.getSpeed() + "，现在能量为：" + car.getPower());
    }
}
