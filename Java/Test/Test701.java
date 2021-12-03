package Test;

import java.lang.Thread;
public class Test701 {

    public static void main(String[] args) throws InterruptedException {
        Runnable r1 = () -> {
            for (int i=0; i<100; i++) {
                System.out.println(1);
            }
        };
        Runnable r2 = () -> {
            for (int i=0; i<100; i++) {
                System.out.println(2);
            }
        };
        Thread t1 = new Thread(r1);
        Thread t2 = new Thread(r2);
        t1.start(); t2.start();
    }
}
