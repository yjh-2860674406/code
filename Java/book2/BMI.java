package Java.book2;

import java.util.Scanner;

public class BMI {
    public static void main(String[] args) {
        System.out.println("请输入体重(kg):");
        Scanner in = new Scanner(System.in);
        double weight = in.nextDouble(); 
        System.out.println("请输入身高(m):");
        double hight = in.nextDouble();
        double bmi = weight/(hight*hight);
        System.out.printf("%.2f", bmi);
        in.close();
    }
}