package Book.book7;

public class book7_Rectangle extends book7_Graphics {
    private double l;
    private double w;

    public book7_Rectangle (double l, double w) {
        this.l = l; this.w = w;
    }

    public book7_Rectangle () {
        l = w = 0;
    }

    public double getArea () {
        return l*w;
    }

    public double getPerimeter () {
        return 2*(l+w);
    }
}
