package TestClass.Four.thirteen;

import java.util.HashSet;
import java.util.Random;
import java.util.TreeSet;

public class Random_hash {
    public static void main(String[] args) {
        Random ran = new Random();   // 新建随机类
        int[] array = new int[10];   // 新建数组
        for (int i=0; i<10; i++) array[i] = ran.nextInt(90) + 10;  // 添加随机数进数组
        HashSet<Integer> h = new HashSet<Integer>();   // hashset
        TreeSet<Integer> t = new TreeSet<Integer>();   // treeset
        for (int i=0; i<10; i++) {  // 分别添加进 hashset 和 treeset 里面
            h.add(array[i]);
            t.add(array[i]);
        }
        System.out.printf("   初始 集合：");
        for (int i:array) System.out.print(i+" ");  // 打印一开始的数组
        System.out.println();
        System.out.printf("Hashset 集合："); System.out.println(h);                      // 打印hashset 
        System.out.printf("Treeset 集合："); System.out.println(t);                      // 打印treeset
        // 对比结果
    }
}
