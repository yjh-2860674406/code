package TestClass.Two.four;

public class For {
    public static void main(String[] args) {
        int[] array = new int[5];
        for (int i : array) {
            array[i] = i;
        }
        for (int i : array) {
           System.out.println(i); 
        }
    }
}
