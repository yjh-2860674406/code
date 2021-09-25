package Java.ThreeKiller;

import java.util.Scanner;

public class shu {
    public abstract class shujiang extends people {

        public shujiang (String name, int life) {
            super(name, life);
            nation nat = nation.蜀;
            super.setNation(nat);
        }

        public abstract void skill1(people me, people other);
        public abstract void skill2(people me, people other);
    }

    public class LiuBei extends shujiang{
        public LiuBei (String name, int life) {
            super(name, life);
        }

        @Override
        public void skill1(people me, people other) {
            
        }

        @Override
        public void skill2(people me, people other) {

        }
    }
}
