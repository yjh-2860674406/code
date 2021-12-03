package Book.book4;

import java.util.Scanner;

public class book4_Stock {

    private String symbol;
    private String name;
    private double previousPrice;
    private double currentPrice;

    public book4_Stock (String symbol, String name) {
        this.symbol = symbol; this.name = name;
    }

    public double getChangPrecent () {
        double percent;
        percent = (currentPrice - previousPrice) / previousPrice ;
        percent *= 100;
        return percent;
    }

    public void setPrevious (double previousPrice) {
        this.previousPrice = previousPrice;
    }

    public void setCurrent (double currentPrice) {
        this.currentPrice = currentPrice;
    }

    public String getSymbol () {
        return symbol;
    }

    public String getName () {
        return name;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("请输入股票代码：");
        String symbol = in.nextLine();
        System.out.println("请输入股票名字：");
        String name = in.nextLine();
        book4_Stock stock = new book4_Stock(symbol, name);
        System.out.println("请输入上一次的价格：");
        stock.setPrevious(in.nextDouble());
        System.out.println("请输入当前的价格：");
        stock.setCurrent(in.nextDouble());
        in.close(); System.out.printf("%s：股票代码：%s 价格涨跌百分比：%.2f\n", stock.getName(), stock.getSymbol(),  stock.getChangPrecent());
    }
}
