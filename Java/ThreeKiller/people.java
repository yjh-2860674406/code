package Java.ThreeKiller;

enum identity {主公, 忠臣, 反贼, 内奸}
enum nation {魏, 蜀, 吴, 群}

public class people {
    private String name;
    // 武将名
    private int life;
    // 血量
    private int life_max;
    // 血量上限
    private identity id;
    // 身份
    private nation nat;
    // 国籍
    private int length;
    // 当前牌的数量
    private poker[] pokers; 
    // 牌组

    people (String name, int life) {
        // 构造器
        this.name = name;
        this.life_max = this.life = life; length = 10;
        // 血量等于血量上限等于初始血量
    }

    public String toString () {
        // 输出名字和血量和血量上限
        return "武将名："+name+'\n'+"血量："+life+'/'+life_max+'\n';
    }

    protected void setId (identity id) {
        // 设置身份
        this.id = id;
    }

    protected void setNation (nation nat) {
        // 设置国籍
        this.nat = nat;
    }

    public void hurted () {
        // 受到伤害
        life--;
    }

    public void cure () {
        // 治疗
        life++;
    }

    public poker getPoker (int i) {
        // 取得牌
        poker po = pokers[i];
        pokers[i] = pokers[length-1];
        return po;
    }

    public void addPoker (poker po) {
        // 添加牌
        pokers[length] = po;
    }
}
