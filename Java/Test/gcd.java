package Test;

public class gcd {
    public static int getGcd (int x, int y) {
        if (x>y) return getGcd(x-y, y);
        else if (x<y) return getGcd(x, y-x);
        else return x;
    }

    public static void main(String[] args) {
        int x=11, y=24;
        System.out.println(getGcd(x, y));
    }
}
