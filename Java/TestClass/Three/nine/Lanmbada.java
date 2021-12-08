package TestClass.Three.nine;

import java.util.*;
public class Lanmbada {
    public static void main(String[] args) {
        // lambda表达式
        Comparator<String> s = (String a, String b) -> {
            return b.compareTo(a);
        };
        String[] sa = {"east", "west", "south", "north"};
        for (String s2 : sa) System.out.print(s2+" ");
        Arrays.sort(sa, s);
        System.out.println();
        for (String s2:sa) System.out.print(s2+" ");
    }
}
