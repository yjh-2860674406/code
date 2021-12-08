package TestClass.Two.three;

public class Vehicle {
    private double speed;
    private int power;

    public Vehicle () {
        this.speed = 0; this.power = 0;
    }

    public void speedUp (int s) {
        this.speed += s;
        this.power -= s;
    }

    public void speedDowm (int s) {
        this.speed -= s;
        this.power -= s/2;
    }

    public double getSpeed () {
        return this.speed;
    }

    public void setPower (int p) {
        this.power = p;
    }

    public int getPower () {
        return this.power;
    }
}
