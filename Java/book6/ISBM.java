package Java.book6;

import java.util.Scanner;

public class ISBM {
    public static int judgeISBN (String isbn) {
        if (isbn.length() != 17) return 0;
        int num = 0;
        for (int i=0; i<17; i++) {
            char x = isbn.charAt(i);
            if (x != '-') {
                if (x < '0' && x > '9') {
                    return 0;
                }
            } else num++;
        }
        if (num == 4) return 1;
        return 0;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("请输入ISBN码：");
        String isbn = in.nextLine();
        int n = judgeISBN(isbn);
        if (n == 1) {
            System.out.println("合法");
        } else {
            System.out.println("不合法");
        }
        in.close();
    }
}
