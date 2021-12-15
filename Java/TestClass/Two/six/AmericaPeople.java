package TestClass.Two.six;

public class AmericaPeople extends People {

    public AmericaPeople() {
        super(); this.height = 1.74; this.weight = 88;
    }
    public void speakHello () {
        System.out.println("Hello,I am a american!");
    }
    public void averageHeight () {
        System.out.println("average of american height ：" + this.height + "m!");
    }
    public void averageWeight () {
        System.out.println("average of american weight ：" + this.weight + "kg!");
    }
    public void americaBoxing () {
        System.out.println("I can boxing!");
    }
}
