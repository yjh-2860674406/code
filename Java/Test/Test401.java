package Java.Test;

import java.lang.reflect.Array;
import java.util.Arrays;

public class Test401 {
    public static void main(String[] args) {
        int num = 5;
        int[] array = new int[num];
        for (int i=0; i<num; i++) array[i] = 0;
        for (int i : array) System.out.println(i);


        int[] array1 = {1,1,1,1,1};
        System.arraycopy(array1, 0, array, 0, 5);
        for (int i : array) System.out.println(i);

        
        int[] array3 = Arrays.copyOf(array, array.length);
        for (int i : array3) System.out.println(i);
    }
}
