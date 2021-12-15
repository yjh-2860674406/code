package CY;

import java.io.IOException;

public class Methodexception {
   public static void methodA() throws IOException{
        throw new IOException("a exception!");
   } 

   public static void methodB() throws IOException{
       methodA();
   }

   public static void main(String[] args) throws IOException {
       try{
           methodB();
       }catch(IOException e){
           System.out.println(e);
       }
   }

}
