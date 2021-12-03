package Book.book2;

import java.util.Scanner;

public class book2_Loan {
    public static void main(String[] args) {
        double year_rate;
        double mouth_rate;
        double all_money;
        int year;

        Scanner in = new Scanner(System.in);
        System.out.println("请输入贷款总数(元)："); all_money = in.nextDouble();
        System.out.println("请输入贷款年利率："); year_rate = in.nextDouble(); mouth_rate = year_rate/12;
        System.out.println("请输入贷款年数："); year = in.nextInt(); in.close();

        double mouth_pay = (all_money*mouth_rate)/(1-1/Math.pow(1+mouth_rate, year*12));
        System.out.printf("月付：%.2f(元)\n", mouth_pay);
        System.out.printf("总金额：%.2f(元)", mouth_pay*12*year);
    }
}
