package Java.book3;

import java.util.Random;
import java.util.Scanner;

public class Game {
    public static void main(String[] args) {
        int player;
        int computer;
        System.out.println("你出什么？(石头(2)、剪刀(1)、布(0))");
        Scanner in = new Scanner(System.in);
        Random random = new Random();
        computer = random.nextInt(3);
        player = in.nextInt(); in.close(); 
        int res = player - computer;
        String[] type = {"布", "剪刀", "石头"};
        if (res == 1 || res == -2) {
            System.out.println("电脑出的是：" + type[computer] + "，你出" + type[player] + "，你赢了。");
        }
        else if (res == 0) {
            System.out.println("电脑出的是：" + type[computer] + "，你出" + type[player] + "，平局。");
        } else {
            System.out.println("电脑出的是：" + type[computer] + "，你出" + type[player] + "，你输了。");
        }
    }
}
