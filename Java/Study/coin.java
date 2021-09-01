package Java.Study;

import java.util.HashMap;
import java.util.Scanner;

public class coin {
    private HashMap<Integer, String> coinnames = new HashMap<Integer, String>();
    
    public coin() {
        coinnames.put(1,"penny");
        coinnames.put(10, "dime");
        coinnames.put(25, "quarter");
        coinnames.put(50, "half-dolar");
    }

    public String getName(int amount) {
        if (coinnames.containsKey(amount)) return coinnames.get(amount);
        else return "Not Found";
    }
    
    public static void main (String[] args)
    {
        Scanner in = new Scanner(System.in);
        int amount = in.nextInt();
        coin coin = new coin();
        String name = coin.getName(amount);
        System.out.println(name);
    } 
}
