package Book.book11;

public class book11_Point<T> {
    private T x;
    private T y;

    public book11_Point (T x, T y) {
        this.x = x; this.y = y;
    }

    public void setterX (T x) {
        this.x = x;
    }

    public void setterY (T y) {
        this.y = y;
    }

    public T getterX () {
        return this.x;
    }
    
    public T getterY () {
        return this.y;
    }

    public void translate (T x, T y) {
        this.x = x; this.y = y;
    }

    @Override
    public String toString() {
        return x.toString() + "," + y.toString();
    }


    public static void main(String[] args) {
        book11_Point<Double> a = new book11_Point<Double>(3.14, 6.28);
        System.out.println(a.toString());
        a.translate(5.12, 13.4);
        System.out.println(a.toString());
    }

}
