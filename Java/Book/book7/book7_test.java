package Book.book7;

public class book7_test {
    public static void main(String[] args) {
        book7_Rectangular rectangular = new book7_Rectangular(10, 4, 5);
        System.out.println("长方体的长：4 宽：5高：10 表面积：" + rectangular.getArea() + " 体积：" + rectangular.getVolume());
        book7_Cylinder cylinder = new book7_Cylinder(10, 5);
        System.out.println("圆柱体的半径：5 高：10 表面积：" + cylinder.getArea() + " 体积：" + cylinder.getVolume());
        book7_Triangular triangular = new book7_Triangular(10, 3, 4, 5);
        System.out.println("三角柱体的边：3 边：4 边：5 高：10 表面积：" + triangular.getArea() + " 体积：" + triangular.getVolume());
    }
}
