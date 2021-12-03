package Book.book11;

import java.util.PriorityQueue;

public class book11_PriorityQueueTest<T> extends PriorityQueue<T> {
    public static void main(String[] args) {
        book11_PriorityQueueTest<Integer> a = new book11_PriorityQueueTest<>();
        int[] array = {1,5,3,7,6,9,8};
        for (int i=0; i<7; i++) a.add(array[i]);
        a.forEach(System.out::println);  
    }
}
