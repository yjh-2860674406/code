package Java.book10;

public class SequenceTest {
    public static double average (IntSequence seq, int n) {
        int num = 0;
        for (int i=0; i<n; i++) {
            seq.hasNext();
            num += seq.next();
        }
        double res = num/n;
        return res;
    }

    public static void main(String[] args) {
        RandomIntSequence seq = new RandomIntSequence();
        System.out.println(average(seq, 10));
    }
}
