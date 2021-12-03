package Test;
import java.util.Scanner;

public class Test201 {
    public static void main (String[] args) {
        System.out.println("**********以下是计算BMI界面**********");
        System.out.println("请输入体重（公斤）:");
        Scanner in = new Scanner(System.in);
        double weight = in.nextDouble();
        System.out.println("请输入身高（米）: ");
        double hight = in.nextDouble();
        double bmi = weight/(hight*hight);
        System.out.printf("您的BMI是：%.1f", bmi);
    }
}