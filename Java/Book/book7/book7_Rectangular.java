package Book.book7;

public class book7_Rectangular extends book7_Rectangle {
    private double height;

    public book7_Rectangular () {
        super();
        height = 0;
    }

    public book7_Rectangular (double height, double l, double w) {
        super(l, w);
        this.height = height;
    }

    public double getArea () {
        double area = super.getArea();
        double perimeter = super.getPerimeter();
        return area*2+perimeter*height;
    }

    public double getVolume () {
        double area = super.getArea();
        return area*height;
    }
}
