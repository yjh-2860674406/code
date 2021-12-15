package TestClass.Five.seventeen;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;

public class Student implements Serializable {
    private String name;
    private int age;
    private double height;
    private double weight;
    public Student (String name, int age, double height, double weight) {
        this.name = name; this.age = age;
        this.height = height; this.weight = weight;
    }
    @Override
    public String toString() {
        return "姓名：" + name + " 年龄：" + age + " 身高：" +
        height + " m" + " 体重：" + weight + " kg";
    }

    public static void main(String[] args) throws IOException, ClassNotFoundException {
        Student YJH = new Student("yjh", 19, 1.71, 74);
        FileOutputStream out = new FileOutputStream("D:\\code\\Java\\TestClass\\Five\\seventeen\\yjh\\student.dat");
        ObjectOutputStream out_s = new ObjectOutputStream(out);
        out_s.writeObject(YJH);
        out.close();
        FileInputStream in = new FileInputStream("D:\\code\\Java\\TestClass\\Five\\seventeen\\yjh\\student.dat");
        ObjectInputStream in_s = new ObjectInputStream(in);
        Object yjh = in_s.readObject();
        in_s.close();
        System.out.println(yjh.toString());
    }
}
