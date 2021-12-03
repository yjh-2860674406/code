package Book.book8;

import java.time.LocalDate;

public class book8_Day {
    public static void main(String[] args) {
        LocalDate newYear = LocalDate.of(2017, 1, 1);
        LocalDate day = newYear.plusDays(256);
        // System.out.println(newYear);
        System.out.println("2017年程序员日：" + day);
    }
}
