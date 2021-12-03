package Test;

import java.util.stream.Stream;
import java.math.*;
import TestClass.Four.fourteen.stream;

/**
 * ArrayAlg
 */
public class ArrayAlg {
    public static void main(String[] args) {
        Stream x = Stream.generate(Math::random);
        x.forEach(str->System.out.println(str));
    }
}