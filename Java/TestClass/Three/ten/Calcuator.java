package TestClass.Three.ten;

public interface Calcuator {
    double calculate (int a, int b);
    default int substract (int a, int b) {
        return a-b;
    } 
    default int add (int a, int b) {
        return a+b;
    }
}
