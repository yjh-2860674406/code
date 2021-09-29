package Java.cy;

public class Stock {
    private String symbol;
    private String name;
    private double previousPrice;
    private double currentPrice;

    public Stock(String symbol,String name){
        this.symbol = symbol;
        this.name = name;
    }

    public void getdata(double previous,double current){
        this.previousPrice = previous;
        this.currentPrice = current; 
    } 

    public double getChangePrice(){
        return (this.currentPrice - this.previousPrice)/this.previousPrice;
    }

    public static void main(String[] args) {
        Stock stock_1 = new Stock("600000","浦发银行" );
        stock_1.getdata(25.5, 28.6);
        System.out.println(stock_1.getChangePrice());
    }

}