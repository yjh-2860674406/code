package TestClass.Two.five;

import java.io.File;

public class Test_1 {
    public static void main(String[] args) {
        int one = 0;
        for (int i = 0; i < args.length; i++) {
            if (args[i].equals("-V")) {
                if (one == 0) {
                    System.out.println(System.getProperty("java.version"));
                    one++;
                } else {
                    System.out.println("选项错误！");
                }
            } else if (args[i].equals("-h")) {
                if (one == 0) {
                    System.out.println("-V get version");
                    System.out.println("-f read file");
                    System.out.println("-v other imformation");
                    one++;
                } else {
                    System.out.println("选项错误！");
                }
            } else if (args[i].equals("-f")) {
                i++;
                String name = args[i];
                if (name.charAt(0) == '-') {
                    System.out.println("-f选项错误，需要文件名！");
                    break;
                } else {
                    File file = new File(name);
                    if (file.exists()) {
                        System.out.println("文件读取成功！");
                    } else {
                        System.out.println("文件不存在！"); {}
                    }
                }
            } else if (args[i].equals("-v")) {
                System.out.println("emmm,我也不知道显示什么信息");
            } else {
                System.out.println("输入参数错误！");
            }
        }
    }
}


