package TestClass.Five.seventeen;

import java.io.DataOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;

public class dataout {
    public static void main(String[] args) throws IOException {
        File file = new File("D:\\code\\Java\\TestClass\\Five\\seventeen\\yjh\\out.dat");
        FileOutputStream out = new FileOutputStream(file);
        DataOutputStream out_data = new DataOutputStream(out);
        out_data.writeByte(1);
        out_data.writeShort(2);
        out_data.writeInt(3);
        out_data.writeLong(4);
        out_data.writeDouble(3.14);
        out_data.writeFloat(5);
        out_data.writeChar('a');
        out_data.writeBoolean(true);
        out_data.writeChars("YJH");
        out_data.close();
    }
}
