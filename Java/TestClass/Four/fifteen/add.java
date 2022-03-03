package TestClass.Four.fifteen;

import java.util.InputMismatchException;
import java.util.Scanner;

public class add {
    public static void main(String...args) {
        caculate();
    }
    public static int caculate () {
        int x=0, y=0, res=0;        
        Scanner in = new Scanner(System.in);
        try {
            System.out.println("请输入第一个整数：");
            x = in.nextInt();
            System.out.println("请输入第二个整数：");
            y = in.nextInt();
        } catch (InputMismatchException e) {
            System.out.println("请输入整数类型的数据！");
            x = 0; y = 0;
        } catch (ArithmeticException e) {
            System.out.println(e.getMessage());
        }
        res = x+y;
        System.out.println("结果为：" + res);        
        in.close();
        return res;
    }
}
