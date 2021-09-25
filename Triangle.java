public class Triangle {
    private double a,b,c;
    public Triangle(){
        // this.a = 0.0;
        // this.b = 0.0;
        // this.c = 0.0;
    }
    public Triangle(double a,double b,double c){
        this.a = a;
        this.b = b;
        this.c = c;
    }

    public double getArea(){
        double s;
        s = (this.a+this.b+this.c)/2;
        return Math.sqrt(s*(s-this.a)*(s-this.b)*(s-this.c));
    }

    public static void main(String[] args) {
        Triangle atriangle = new Triangle();
        System.out.println(atriangle.getArea());        

    }
}
