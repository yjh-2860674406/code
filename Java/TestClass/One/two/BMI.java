package TestClass.One.two;

import java.util.Scanner;

public class BMI {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        double height = 0, weight = 0;
        System.out.println("请输入身高（m）：");
        height = in.nextDouble();
        System.out.println("请输入体重（kg）：");
        weight = in.nextDouble();
        double BMI = weight/(height*height);
        System.out.printf("BMI 为：%.2f", BMI);
        in.close();
    }
}
