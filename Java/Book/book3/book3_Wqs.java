package Book.book3;

public class book3_Wqs {
    public static void main(String[] args) {
        int num=0; int all=0;
        int[] array = new int[10];
        for (int i=2; i<1001; i++) {
            int p = (int)Math.sqrt(i);
            for (int j=2; j<=p; j++) {
                if (i%j == 0) {
                    all += j;
                    all += (i/j);
                }
            }
            if (++all == i) {
                array[num] = i;
                num++;
            }
            all = 0;
        }
        for (int i=0; i<num; i++) {
            System.out.printf("%d\t", array[i]);
        }
    }
}
