package CY.cy.eleven_four;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class Arraylist_test {
   public static void main(String[] args) {
       List<String> list_1 = new ArrayList<>();
       list_1.add("beijing");
       list_1.add("shanghai");
       list_1.add("guangzhou");
       list_1.add("shenzheng");
       for(int i = 1; i <= list_1.size(); i++){
           list_1.get(i).toUpperCase();
           System.out.println(list_1.get(i)+" ");
       }
       Iterator<String> iterator = list_1.iterator();
       while(iterator.hasNext()){
           System.out.println(iterator.next().toLowerCase());
       }
       list_1.replaceAll(str->str.toUpperCase()); 
   }
}
