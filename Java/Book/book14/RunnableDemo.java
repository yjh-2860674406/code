package Book.book14;

public class RunnableDemo{
    public static void main(String[] args) {
        Runnable task = () -> {
            for (int i=0; i<100; i++) {
                System.out.println(
                    Thread.currentThread().getName()+" = "+i
                );
                try {
                    // 使当前线程睡眠一段时间
                    Thread.sleep((int)(Math.random()*100));
                } catch (InterruptedException e) {}
            }
            System.out.println(Thread.currentThread().getName()+" 结束");
        };
        Thread thread1 = new Thread(task, "线程 A");
        Thread thread2 = new Thread(task, "线程 B");
        thread1.start(); thread2.start();
    }
}
