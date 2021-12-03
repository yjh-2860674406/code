package TestClass.Three.eight;

import java.time.DayOfWeek;
import java.time.LocalDate;

public class FindTime {

    public static void main(String[] args) {
        // LocalDate initialdate = LocalDate.of(2001, 1, 1);
        LocalDate finaldate = LocalDate.of(2099, 12, 31);
        LocalDate rundate = LocalDate.of(2001, 1, 13);
        
        while (rundate.getYear() <= finaldate.getYear()) {
            if (rundate.getDayOfMonth() == 13 && rundate.getDayOfWeek() == DayOfWeek.FRIDAY) {
                System.out.println(rundate);
            } rundate = rundate.plusMonths(1);
        }

    }

}
