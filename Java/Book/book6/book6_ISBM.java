package Book.book6;

import java.util.Scanner;

public class book6_ISBM {
    public static int judgeISBN (String isbn) {
        if (isbn.length() != 17) return 0;
        int[] array = {3,5,9,15};
        for (int i=0; i<4; i++) {
            if (isbn.charAt(array[i]) != '-') return 0;
        }
        int j = 0; int num = 0;
        for (int i=0; i<isbn.length(); i++) {
            if (i == array[j] && j < 3) {
                j++; continue;
            }
            if (isbn.charAt(i) >= '0' && isbn.charAt(i) <= '9') num++;
        }
        if (num == 13) return 1;
        else return 0;
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
