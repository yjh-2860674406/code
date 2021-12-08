package TestClass.Two.six;

public class BeijingPeople extends ChinaPeople {

    public BeijingPeople() {
        super(); this.height = 1.71; this.weight = 71.4;
    }

    public void speakHello () {
        System.out.println("你好，我是北京居民！");
    }

    public void averageHeight () {
        System.out.println("北京居民的平均身高：" + this.height + "m!");
    }

    public void averageWeight () {
        System.out.println("北京居民的平均体重：" + this.weight + "kg!");
    }

    public void beijingOpera () {
        System.out.println("我会唱京剧！");
    }
    
}
