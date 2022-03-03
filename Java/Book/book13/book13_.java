package Book.book13;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Random;

public class book13_ {
    public static void main(String[] args) throws IOException {
        Random ran = new Random();
        DataOutputStream data_out = new DataOutputStream(new FileOutputStream("D:\\code\\Java\\Book\\book13\\data.dat"));
        for (int i=0; i<10; i++) {
            data_out.writeInt(ran.nextInt(1000)+1000);
        }
        data_out.close();
        DataInputStream data_in = new DataInputStream(new FileInputStream("D:\\code\\Java\\Book\\book13\\data.dat"));
        for (int i=0; i<10; i++) {
            System.out.println(data_in.readInt());
        }
        data_in.close();
    }
}
