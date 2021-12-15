package Book.book14;

public class Counter_block {
    private int count;
    public Counter_block () {
        this.count = 0;
    }

    public int increment () {
        synchronized (this) {
            this.count++;
        } return this.count;
    }

    public static void main(String[] args) {
        Counter_block counter = new Counter_block();
        Runnable task = () -> {
            for (int i=0; i<100; i++) {
                System.out.println(Thread.currentThread().getName() + 
                " 的count: " + counter.increment());
                try {
                    Thread.sleep((int)(Math.random()*100));
                } catch (Exception e) {}
            }
            System.out.println(Thread.currentThread().getName() + 
            " 结束");
        };
        for (int i=0; i<100; i++) {
            Thread thread = new Thread(task, Integer.toString(i));
            thread.start();
        }
    }    
}
