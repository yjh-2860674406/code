package Book.book10;

interface book10_Calculator {
    public int add (int a, int b);
    public int sub (int a, int b);

    public default int substract (int a, int b) {
        return a-b;
    }

    // public default int add (int a, int b) {
    //     return a+b;
    // }
}