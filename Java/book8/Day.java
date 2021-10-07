package Java.book8;

import java.time.LocalDate;

public class Day {
    public static void main(String[] args) {
        LocalDate newYear = LocalDate.of(2017, 1, 1);
        LocalDate day = newYear.plusDays(256);
        System.out.println(day);
    }
}
