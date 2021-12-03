package Book.book8;

public class book8_Square {
    private int length;

    public book8_Square (int length) {
        this.length = length;
    }

    @Override
    protected Object clone() throws CloneNotSupportedException {
        book8_Square other = new book8_Square(this.length);
        return other;
    }

    @Override
    public boolean equals(Object other) {
        book8_Square other_c = (book8_Square)other;
        if (other_c.length == this.length) return true;
        else return false;
    }

    @Override
    public String toString() {
        return "Square[length=" + this.length + "]";
    }

    public static void main(String[] args) throws CloneNotSupportedException {
        book8_Square x = new book8_Square(100);
        book8_Square y = (book8_Square)x.clone();
        if (x.equals(y)) {
            System.out.println("equals");
        } else {
            System.out.println("no equals");
        }
        System.out.println(x.toString());
        System.out.println(y.toString());
    }
}
