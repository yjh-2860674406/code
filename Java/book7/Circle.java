package Java.book7;

public class Circle {
    private double centerX;
    private double centerY;
    private double radius;

    public Circle (double radius) {
        this.radius = radius;
    }

    public Circle () {
        radius = 0;
    }

    public double getArea () {
        return radius*radius*3.14;
    }

    public double getPerimeter () {
        return 6.28*radius;
    }

    public double getRadius () {
        return radius;
    }

    public void setRadius (double radius) {
        this.radius = radius;
    }
}