package Book.book13;

import java.io.File;
import java.util.Scanner;

public class book13_Rename {
    public static void main(String[] args) {
        System.out.println("请输入文件的路径：");
        Scanner in = new Scanner(System.in);
        String name_old = in.next();
        System.out.println("请输入修改后的文件名：");
        String name_new = in.next();
        in.close();
        File file = new File(name_old);
        if (file.exists()) {
            file.renameTo(new File(name_new));
            System.out.println("修改成功！");
        } else {
            System.out.println("不存在源文件！");
        }
    }
}
