package TestClass.Five.eighteen;

public class abc {
   
    public static void main(String[] args) {
        Runnable printa = new Runnable() {
            @Override
            public void run() {
                for (int i=0; i<100; i++) {
                    System.out.println("a");
                }
            }
        };
        Runnable printb = new Runnable() {
            @Override
            public void run() {
                for (int i=0; i<100; i++) {
                    System.out.println("b");
                }
            }
        };
        Runnable printnum = new Runnable() {
            @Override
            public void run() {
                for (int i=1; i<=100; i++) {
                    System.out.println(i);
                }
            }
        };
        new Thread(printa).start();
        new Thread(printb).start();
        new Thread(printnum).start();
    }
}
