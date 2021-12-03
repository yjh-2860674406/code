package TestClass.Four.fourteen;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.function.Predicate;
// import java.util.stream.Collector;
// import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class stream {
    public static void main(String[] args) {
        Random ran = new Random();
        List<Integer> array = new ArrayList<Integer>();
        for (int i=0; i<1000; i++) array.add(ran.nextInt(900) + 100);
        Stream<Integer> s = array.stream();
        Predicate<Integer> seven = (Integer i) -> {return i.intValue() % 7 == 0;};
        List<Integer> res = new ArrayList<Integer>();
        res = s.filter(seven).collect(Collectors.toList());
        System.out.println(res.toString());
    }
}