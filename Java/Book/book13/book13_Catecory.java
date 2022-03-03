package Book.book13;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.nio.charset.Charset;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;

public class book13_Catecory {
    public static void main(String[] args) throws IOException {
        System.out.println("请输入源文件路径：");
        Scanner in = new Scanner(System.in);
        String path = in.next();
        in.close();
        InputStream file = new FileInputStream(path);
        char[] words = new char[200];
        try (InputStreamReader file_stream = new InputStreamReader(file, Charset.forName("utf-8"))) {
            file_stream.read(words, 0, 199);
        } catch (Exception e) {
            System.out.println("出错了！");
        }
        String string = new String(words);
        String[] word_array = GetWord(string);
        System.out.println("文本中的单词：");
        for (int i=0; i<word_array.length&&word_array[i]!=null; i++) {
           System.out.println(word_array[i]);
        }
        List<String> res_1 = new ArrayList<>();
        HashSet<String> res_2 = new HashSet<>();
        for (int i=0; i<word_array.length&&word_array[i]!=null; i++) {
            if (res_1.indexOf(word_array[i]) == -1) {
                res_1.add(word_array[i]);
            } else res_2.add(word_array[i]);
        }
        System.out.println("不重复的单词：");
        for (String s1 : res_1) {
            System.out.println(s1);
        }
        System.out.println("重复的单词：");
        for (String s2 : res_2) {
            System.out.println(s2);
        }
    }

    public static String[] GetWord (String string) {
        String[] words = new String[20];
        int x = 0, y = 0;
        char[] word = new char[20];
        for (int i=0; i<string.length()&&(int)string.charAt(i)!=0; i++) {
            if (string.charAt(i) != ' ') {
                word[y++] = string.charAt(i);
            } else {
                words[x++] = new String(word);
                word = new char[20];
                y = 0;
            }
        }
        words[x] = new String(word);
        return words;
    }
}
