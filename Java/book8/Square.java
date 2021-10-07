package Java.book8;

public class Square {
    private int length;

    public Square (int length) {
        this.length = length;
    }

    public Square clone () {
        Square copy = new Square(this.length);
        return copy;
    }

    public int equals (Square other) {
        if (this.length == other.length) return 1;
        else return 0;
    }

    public String toString () {
        return "Square[length=" + length + "]";
    }

    public static void main(String[] args) {
        Square one = new Square(10);
        System.out.println(one.toString());
    }
}
