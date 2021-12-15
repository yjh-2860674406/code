package TestClass.Two.six;

public class ChinaPeople extends People {

    public ChinaPeople() {
        super(); this.height = 1.70; this.weight = 69.6;
    }
    public void speakHello () {
        System.out.println("你好，我是中国人！");
    }
    public void averageHeight () {
        System.out.println("中国人的平均身高：" + this.height + "m!");
    }
    public void averageWeight () {
        System.out.println("中国人的平均体重：" + this.weight + "kg!");
    }
    public void chinaGongfu () {
        System.out.println("我会打功夫！");
    }
}
