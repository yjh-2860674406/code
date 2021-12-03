package Book.book7;

public class book7_Cylinder extends book7_Circle {
    private double height;

    public book7_Cylinder () {
        super();
        height = 0;
    }

    public book7_Cylinder (double height, double radius) {
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
