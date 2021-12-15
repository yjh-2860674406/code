package TestClass.Four.sixteen;

import java.util.Arrays;
import java.util.stream.Stream;

import TestClass.Four.fourteen.stream;

public class optional {
    public static void main(String[] args) {
        String[] ss = new String[4];
        ss[0] = "YJH"; ss[1] = "is"; ss[2] = "a"; ss[3] = "student";
        Stream<String> stream = Arrays.stream(ss);
        System.out.println("数组第一个元素：" + stream.findFirst().get());
    }
}
