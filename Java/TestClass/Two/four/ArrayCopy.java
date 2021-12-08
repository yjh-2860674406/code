package TestClass.Two.four;

public class ArrayCopy {
    public static void main(String[] args) {
        int[] array = new int[5];
        int[] src = {0,1,2,3,4};
        System.arraycopy(src, 0, array, 0, 5);
        for (int i : array) {
            System.out.println(i);
        }
    }
}
