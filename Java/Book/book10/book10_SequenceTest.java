package Book.book10;

public class book10_SequenceTest {
    public static double average (book10_IntSequence seq, int n) {
        int num = 0;
        for (int i=0; i<n; i++) {
            seq.hasNext();
            num += seq.next();
        }
        double res = num/n;
        return res;
    }

    public static void main(String[] args) {
        book10_RandomIntSequence seq = new book10_RandomIntSequence();
        System.out.println(average(seq, 10));
    }
}
