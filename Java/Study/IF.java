import java.util.Scanner;

public class IF {
   public static void main (String[] args)
   {
       System.out.println("��������������:");
       Scanner sc = new Scanner(System.in);
       int age = sc.nextInt();
       if (age < 18)
       {
            System.out.println("δ����");
       }
       else 
       {
           System.out.println("�ѳ���");
       }
       sc.close();
   }
}
