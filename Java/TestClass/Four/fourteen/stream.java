package TestClass.Four.fourteen;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class stream {
    public static void main(String[] args) {
        Random ran = new Random(); // 随机类
        List<Integer> array = new ArrayList<Integer>();  // 定义一个集合
        for (int i=0; i<1000; i++) array.add(ran.nextInt(900) + 100); // 向集合里面添加随机数
        Stream<Integer> s = array.stream();    // 将集合注入流
        List<Integer> res = new ArrayList<Integer>(); // 创建新集合
        res = s.filter(x->x.intValue()%7==0).collect(Collectors.toList()); // 将结果输入新集合里面
        System.out.println(res.toString());   // 打印出结果
    }
}