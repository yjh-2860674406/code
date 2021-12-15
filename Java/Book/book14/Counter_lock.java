package Book.book14;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Counter_lock {
    private int count;
    Lock lock = new ReentrantLock();
    public Counter_lock () {
        this.count = 0;
    }

    public int increment () {
        lock.lock();
        this.count++;
        lock.unlock();
        return this.count;
    }

    public static void main(String[] args) {
        Counter_lock counter = new Counter_lock();
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
