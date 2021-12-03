package Book.book10;

public class book10_test {
    public static void main(String[] args) {
        // Calculator lambda1 = (int a, int b) -> {
        //     System.out.println("hhh");
        //     return a + b;
        // };
        book10_Calculator inter = new book10_Calculator() {
            @Override
            public int add(int a, int b) {
                return a+b;
            }
            @Override
            public int sub(int a, int b) {
                return a-b;
            }
        };
        System.out.println(inter.add(3, 4));
        System.out.println(inter.sub(2, 1));
    }
}
