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
                    System.out.println("ѡ�����");
                }
            } else if (args[i].equals("-h")) {
                if (one == 0) {
                    System.out.println("-V get version");
                    System.out.println("-f read file");
                    System.out.println("-v other imformation");
                    one++;
                } else {
                    System.out.println("ѡ�����");
                }
            } else if (args[i].equals("-f")) {
                i++;
                String name = args[i];
                if (name.charAt(0) == '-') {
                    System.out.println("-fѡ�������Ҫ�ļ�����");
                    break;
                } else {
                    File file = new File(name);
                    if (file.exists()) {
                        System.out.println("�ļ���ȡ�ɹ���");
                    } else {
                        System.out.println("�ļ������ڣ�"); {}
                    }
                }
            } else if (args[i].equals("-v")) {
                System.out.println("emmm,��Ҳ��֪����ʾʲô��Ϣ");
            } else {
                System.out.println("�����������");
            }
        }
    }
}


