package TestClass.Five.eighteen;

public class labc {
    public static void main(String[] args) {
        Runnable printa = () -> {
            for (int i=0; i<100; i++) {
                System.out.println("a");
            }
        };
        Runnable printb = () -> {
            for (int i=0; i<100; i++) {
                System.out.println("b");
            }
        };
        Runnable printnum = () -> {
            for (int i=1; i<=100; i++) {
                System.out.println(i);
            }
        };
        new Thread(printa).start();
        new Thread(printb).start();
        new Thread(printnum).start();
    }
}
