package Book.book7;

public class book7_Triangular extends book7_Triangle {
    private double height;

    public book7_Triangular () {
        super();
        height = 0;
    }

    public book7_Triangular (double height, double a, double b, double c) {
        super(a,b,c);
        this.height = height;
    }

    public double getArea () {
        double area = super.getArea();
        double perimeter = super.getPerimeter();
        return 2*area + height*perimeter;
    }

    public double getVolume () {
        double area = super.getArea();
        return area*height;
    }

}
