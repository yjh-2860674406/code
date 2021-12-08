package TestClass.Two.four;

import java.util.Arrays;

public class CopyOf {
    public static void main(String[] args) {
        int[] src = {0,1,2,3,4};
        int[] array = Arrays.copyOf(src, 5);
        for (int i : array) {
            System.out.println(i);
        }
    }
}
