package Book.book3;

import java.util.Scanner;

public class book3_ChickenRabbit {
    public static void main(String[] args) {
        int num_Chicken; int num_Rabbit; int num_leg; int all;
        Scanner in = new Scanner(System.in);
        System.out.println("请输入鸡和兔的总数：");
        all = in.nextInt();
        System.out.println("请输入鸡和兔的脚数：");
        num_leg = in.nextInt(); in.close();;
        num_Chicken = (4*all - num_leg)/2;
        num_Rabbit = all - num_Chicken;
        System.out.println("鸡有：" + num_Chicken + " 个，兔有：" + num_Rabbit + " 个");
    }
}