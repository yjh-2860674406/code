package TestClass.Four.thirteen;

import java.util.HashSet;
import java.util.Random;
import java.util.TreeSet;

public class Random_hash {
    public static void main(String[] args) {
        Random ran = new Random();
        int[] array = new int[10];
        for (int i=0; i<10; i++) array[i] = ran.nextInt(90) + 10;
        HashSet<Integer> h = new HashSet<Integer>();
        TreeSet<Integer> t = new TreeSet<Integer>();
        for (int i=0; i<10; i++) {
            h.add(array[i]);
            t.add(array[i]);
        }
        for (int i:array) System.out.print(i+" ");
        System.out.println();
        System.out.println(h);
        System.out.println(t);
    }
}
