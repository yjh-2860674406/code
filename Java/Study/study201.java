package Study;

import java.lang.reflect.Array;
import java.util.Arrays;

public class study201 {

    public interface Comparable {
        int compareTo (Object o);
    }

    public static class Animal implements Comparable{
        private String name;
        private int age;
        private int food = 100;
        private int life = 100;

        public Animal (String name, int age) {
            this.name = name;
            this.age = age;
            if (this.name == null) this.name = "unkown";
        }

        public void Play () {
            System.out.println(name+"正在玩耍!");
            food-=10;
        }
        public void GetFood () {
            System.out.println(name+"正在吃饭!");
            food+=20;
            if (food > 100) food = 100;
        }   
        public void hurt (Animal animal) {
            animal.life -= 10;
        }
        public int GetLife () {
            return life;
        }
        
        public int compareTo(Object o) {
            Animal other = (Animal)o;
            return (this.age - other.age);
        }

        public String toString () {
            return name;
        }

    }

    public static class Dog extends Animal{
        private String kind;

        public Dog (String name ,int age, String kind) {
            super(name, age);
            this.kind = kind;
        }

        public String GetName() {
            return super.name;
        }

        public int GetLife () {
            super.life += 10;
            return super.life;
        }
    }

    public static void main(String[] args) {
        Animal[] dogs = new Animal[3];
        Animal hapy = new Animal("Hapy", 4);
        Animal cat = new Animal("miao", 3);
        Animal haba = new Animal("haba", 2);
        Arrays.sort(dogs);
        for (int i=0; i<3; i++) {
            System.out.println(dogs[i].toString());
        }
    }
}
