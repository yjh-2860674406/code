package TestClass.Two.six;

public class test {
    public static void main(String[] args) {
        AmericaPeople a = new AmericaPeople();
        ChinaPeople b = new ChinaPeople();
        BeijingPeople c = new BeijingPeople();
        a.speakHello();a.averageHeight();a.averageWeight();a.americaBoxing();
        b.speakHello();b.averageHeight();b.averageWeight();b.chinaGongfu();
        c.speakHello();c.averageHeight();c.averageWeight();c.beijingOpera();
    }
}
