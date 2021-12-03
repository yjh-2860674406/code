package Book.book12;

public class book12_test {
    public static void main(String[] args) {
        book12_myexception a = new book12_myexception("book12");
        try {
            throw a;
        } catch (book12_myexception e) {
            //TODO: handle exception
            e.Print();
        }
    }
}
