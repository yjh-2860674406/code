package TestClass.Three.ten;

import java.util.Scanner;

@FunctionalInterface
interface Calcuator {
    double calculate (int a, int b);
    default int substract (int a, int b) {
        return a-b;
    } 
    default int add (int a, int b) {
        return a+b;
    }
}

public class test {
    public static void main(String[] args) {
        Calcuator sq = (int a, int b) -> {return a*a + b*b;}; // lamda表达式
        Scanner in = new Scanner(System.in);
        System.out.println("请输入要计算的两个数字：");
        int x = in.nextInt(), y = in.nextInt();
        System.out.println("结果：" + sq.calculate(x, y));
        in.close();
    }
}
