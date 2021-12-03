package Book.book12;

import java.io.IOException;

public class book12_A {
    public static void methodA () throws IOException {
        IOException e = new IOException();
        throw e;
    }

    public static void methodB () throws IOException {
        methodA();
    }

    public static void main(String[] args) {
        try {
            methodB();
        } catch (IOException e) {
            
        }
    }

}
