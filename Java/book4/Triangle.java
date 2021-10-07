package Java.book4;

import java.util.Scanner;

public class Triangle {
    private double a;
    private double b;
    private double c;

    public Triangle () {
        a = 0; b = 0; c = 0;
    }

    public Triangle (double a, double b, double c) {
        this.a = a; this.b = b; this.c = c;
    }

    public double getArea () {
        double s = (a+b+c)/2;
        return Math.sqrt(s*(s-a)*(s-b)*(s-c));
    }

    public static void main(String[] args) {
        System.out.println("请输入三角形的三条边：");
        Scanner in = new Scanner(System.in);
        double a = in.nextDouble(), b = in.nextDouble(), c = in.nextDouble();
        in.close();
        Triangle triangle = new Triangle(a,b,c);
        System.out.println("三角形面积：" + triangle.getArea());
    }

}
