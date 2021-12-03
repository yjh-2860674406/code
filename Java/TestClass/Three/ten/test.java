package TestClass.Three.ten;

public class test {
    public static void main(String[] args) {
        Calcuator sq = (int a, int b) -> {return a*a + b*b;};
        System.out.println(sq.calculate(3, 4));
    }
}
