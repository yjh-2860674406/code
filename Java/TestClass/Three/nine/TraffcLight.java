package TestClass.Three.nine;

public enum TraffcLight {
    GREEN("绿灯", 1), RED("红灯", 2), YELLOW("黄灯", 3);
    
    private String name;
    private int index;

    private TraffcLight (String name, int index) {
        this.name = name;
        this.index = index;
    }

    @Override
    public String toString() {
        return this.name;
    }
    

    public static void main(String[] args) {
        TraffcLight[] traffc = {GREEN, RED, YELLOW};
        for (TraffcLight temp : traffc) {
            System.out.print(temp.values() + " ");
            System.out.println(temp.ordinal());
        }
        test(traffc[0]);
        test(traffc[2]);
        test(traffc[1]);
    }

    public static void test (TraffcLight color) {
        switch (color) {
            case GREEN :
                System.out.println(color.toString() + "：可以过马路！");
                break;
            case RED :
                System.out.println(color.toString() + "：禁止过马路！");
                break;
            case YELLOW :
                System.out.println(color.toString() + "：准备停止过马路！");
                break;
        }
    }
}
