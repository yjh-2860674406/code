import java.util.Scanner;

public class Switch {
   public static void main (String[] args)
   {
       System.out.println("请输入两个数字:");
       Scanner sc = new Scanner(System.in);
       int x = sc.nextInt();
       int y = sc.nextInt();
       System.out.println("请输入 1(+) 2(-) 3(*) 4(/)");
       int z = sc.nextInt();
       switch (z)
       {
           case 1:
               System.out.println(x+y);
               break;
           case 2:
                System.out.println(x-y);
                break;
           case 3:
                System.out.println(x*y);
           case 4:
                System.out.println(x/y);
            default :
                System.out.println("输入错误!");
       }
       sc.close();
   }
}
