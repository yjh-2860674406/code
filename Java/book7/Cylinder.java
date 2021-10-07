package Java.book7;

public class Cylinder extends Circle {
    private double height;

    public Cylinder () {
        super();
        height = 0;
    }

    public Cylinder (double height, double radius) {
        super(radius);
        this.height = height;
    }

    public double getArea () {
        double area = super.getArea();
        double perimeter = super.getPerimeter();
        return area*2 + perimeter*height;
    }

    public double getVolume () {
        double area = super.getArea();
        return area*height;
    }
}
