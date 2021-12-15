package TestClass.Three.eight;

import java.util.Scanner;

public class Sushu {
    public static boolean IsSushu (double x) {
        double mid = Math.pow(x, 0.5);
        for (int i=2; i<mid; i++) {
            if (x%i == 0) return false;
        }
        return true;
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("请输入一个数：");
        double num = in.nextDouble();
        if (IsSushu(num)) {
            System.out.println(num + "是一个素数！");
        } else {
            System.out.println(num + "不是一个素数！");
        } in.close();
    }
}
