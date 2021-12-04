package Book.book11;

import java.time.Duration;
import java.time.Instant;
import java.util.Arrays;
import java.util.stream.LongStream;


public class book11_Stream {

    public static void main(String[] args) {
        Mul_test o = x -> {
            int res = 1;
            for (long i=1; i<x; i++) res *= i;
            return res;
        };

        long[] l = new long[4];
        for (long i=1; i<=4; i++) l[(int) (i-1)] = i*10;
        LongStream s1 = Arrays.stream(l);
        Instant start = Instant.now();
        s1.map(input->o.mul(input)).forEach(System.out::println);
        Instant end = Instant.now();
        System.out.println("顺序运行时间：" + Duration.between(start, end).toMillis() + " ms");
        LongStream s2 = Arrays.stream(l);
        start = Instant.now();
        s2.parallel().map(input->o.mul(input)).forEach(System.out::println);
        end = Instant.now();
        System.out.println("并行运行时间：" + Duration.between(start, end).toMillis() + "ms");
    }
}
