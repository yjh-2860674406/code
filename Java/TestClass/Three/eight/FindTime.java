package TestClass.Three.eight;

import java.time.DayOfWeek;
import java.time.LocalDate;

public class FindTime {
    public static void main(String[] args) {
        LocalDate enddata = LocalDate.of(2099, 12, 31);      // 结束时间
        LocalDate rundata = LocalDate.of(2001, 1, 13);       // 目前时间（初始化为2001/1/13）
        
        while (rundata.getYear() <= enddata.getYear()) {  // 当 目前时间 小于 结束时间 时，执行循环
            if (rundata.getDayOfWeek() == DayOfWeek.FRIDAY) {
                // 如果目前时间是星期五，则打印出日期
                System.out.println(rundata);
            } rundata = rundata.plusMonths(1); // 每次把 目前时间 更新一个月
        }
    }
}
