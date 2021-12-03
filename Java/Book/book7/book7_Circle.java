package Book.book7;

public class book7_Circle extends book7_Graphics {
    private double radius;

    public book7_Circle (double radius) {
        this.radius = radius;
    }

    public book7_Circle () {
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