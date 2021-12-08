package TestClass.Three.ten;

interface Calcuator {
    double calculate (int a, int b);
    default int substract (int a, int b) {
        return a-b;
    } 
    default int add (int a, int b) {
        return a+b;
    }
}

public class test {
    public static void main(String[] args) {
        Calcuator sq = (int a, int b) -> {return a*a + b*b;}; // lamda表达式
        System.out.println(sq.calculate(3, 4));
    }
}
