package Book.book10;

import java.util.Random;

public class book10_RandomIntSequence implements book10_IntSequence{
    private int n;

    @Override
    public boolean hasNext() {
        Random ran = new Random();
        n = ran.nextInt(100);
        while (n < 10) {
            n = ran.nextInt(100);  
        }
        return true;
    }

    @Override
    public int next() {
        return n;
    }
}
