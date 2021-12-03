package Book.book11;

import java.util.ArrayList;
import java.util.List;


public class book11_ArrayList {
    public static ArrayList<String> Change_1 (ArrayList<String> a) {
        ArrayList<String> b = new ArrayList<String>();
        for (int i=0; i<a.size(); i++) {
            b.add(a.get(i).toUpperCase());
        }
        return b;
    }

    public static ArrayList<String> Change_2 (ArrayList<String> a) {
        ArrayList<String> b = new ArrayList<String>();
        for (String string : a) {
            b.add(string.toUpperCase());
        }
        return b;
    }

    public static void main(String[] args) {
        String a = "aaa";
        String b = "bbb";
        ArrayList<String> array = new ArrayList<String>();
        array.add(a); array.add(b);
        ArrayList<String> t_1 = Change_1(array);
        ArrayList<String> t_2 = Change_2(array);
        System.out.println(t_1);
        System.out.println(t_2);
    }

}
