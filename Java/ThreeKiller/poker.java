package Java.ThreeKiller;

enum Hua {方块, 梅花, 红心, 黑桃};

public abstract class poker {
    private int dian;
    private Hua hua;
    private String name;
   
    public poker (int dian, Hua hua, String name) {
        this.dian = dian; this.hua = hua; this.name = name;
    }

    public abstract int skill (people me, people other);
}