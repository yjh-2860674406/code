package TestClass.One.two;

public class While {
    public static void main(String[] args) {
        int num = 1;
        while (num <= 1000) {
            if (num++ % 7 == 0) {
                System.out.println(num-1);
            }
        }
    }
}
