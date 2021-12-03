package Book.book12;

public class book12_myexception extends Exception {
    private String string;

    public book12_myexception (String string) {
        this.string = string;
    }

    public void Print() {
        System.out.println(this.string);
    }
}
