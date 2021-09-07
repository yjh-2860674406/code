package Java.Study;
import java.util.Scanner;
public class study101 {
    public static class People {
        public static int age;
        People (int age)
        {
            this.age = age;
        }
        public void getAge() {
            System.out.println(age);
        }
    }
    public static void main (String[] args) {
        People YJH = new People(19);
        People CY = new People(20);
        YJH.getAge();
    }
}