package Java.ThreeKiller;

public class wu {
    public abstract class wujiang extends people {

        public wujiang (String name, int life) {
            super(name, life);
            nation nat = nation.吴;
            super.setNation(nat);
        }

        public abstract void skill1(people me, people other);
        public abstract void skill2(people me, people other);
    }

    public class SunQuan extends wujiang {
        public SunQuan (String name, int life) {
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
