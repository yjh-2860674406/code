package Study;

public class study101 {
    public static class People {
        public int age;
        People (int age)
        {
            this.age = age;
        }
        public void getAge() {
            System.out.println(age);
        }
    }
    public static void main (String[] args) {
        People YJH = new People(19);
        YJH.getAge();
    }
}
