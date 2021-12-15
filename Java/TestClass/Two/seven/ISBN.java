package TestClass.Two.seven;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class ISBN {
    public static void main(String[] args) {
        String model = "^(?:ISBN(?:-13)?:? )?(?=[0-9]{13}$|(?=(?:[0-9]+[- ]){4})[- 0-9]{17}$)97[89][- ]?[0-9]{1,5}[- ]?[0-9]+[- ]?[0-9]+[- ]?[0-9]$";
        // 正则表达式
        String s1 = "978-7-111-50690-4";
        String s2 = "94-3-222-34234-5";
        String s3 = "978-0-596-52068-7";
        String[] ss = new String[3];
        ss[0] = s1; ss[1] = s2; ss[2] = s3;
        // 测试样例
        Pattern pattern = Pattern.compile(model);
        for (String s : ss) {
            Matcher matcher = pattern.matcher(s);
            System.out.printf(s);
            if (matcher.matches()) System.out.println("是ISBN！");
            else System.out.println("不是ISBN！");
        }
    }
}
