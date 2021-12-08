package TestClass.One.two;

public class Dowhile {
    public static void main(String[] args) {
        int num = 1;
        do {
            if (num++ % 7 ==0 ){
                System.out.println(num-1);
            }
        } while (num < 1000);
    }
}
