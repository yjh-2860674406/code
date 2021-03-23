import java.util.Scanner;

public class IF {
   public static void main (String[] args)
   {
       System.out.println("请输入您的年龄:");
       Scanner sc = new Scanner(System.in);
       int age = sc.nextInt();
       if (age < 18)
       {
            System.out.println("未成年");
       }
       else 
       {
           System.out.println("已成年");
       }
       sc.close();
   }
}
