package Java.Test;

import java.io.PipedWriter;

public class Vehicle {
    private double speed;
    private int power;

    public Vehicle () {
        power = 0;
        speed = 0;
    }

    public void speedUp (int s) {
        speed+=s;
        power -= 10;
        System.out.println("现在汽车已经提速 " + s + " 现在的速度是："
        + speed);
    }

    public void speedDowm (int s) {
        speed-=s;

        System.out.println("现在汽车已经提速 " + s + " 现在的速度是："
        + speed);
    }

    public void setPower (int p) {
        System.out.println("现在的能量是：" + p);
        power = p;
    }

    public int getPower() {
        System.out.println("现在的能量是：" + power);
        return power;
    }

    public double getSpeed() {
        System.out.println("现在的速度是：" + speed);
        return speed;
    }


}
