package Book.book7;

public class book7_Triangle extends book7_Graphics {
    private double a, b, c;

    public book7_Triangle (double a, double b, double c) {
        this.a = a; this.b = b; this.c = c;
    }

    public book7_Triangle () {
        a = b = c = 0;
    }

    public double getArea () {
        double s = (a+b+c)/2;
        return Math.sqrt(s*(s-a)*(s-b)*(s-c));
    }

    public double getPerimeter () {
        return a+b+c;
    }
}
