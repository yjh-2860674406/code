package Java.ThreeKiller;

public class wei {
    public abstract class weijiang extends people {
        public weijiang (String name, int life) {
            super(name, life);
            nation nat = nation.魏;
            super.setNation(nat);
        }

        public abstract void skill1(people me, people other);
        public abstract void skill2(people me, people other);
    }

    public class CaoChao extends weijiang {
        public CaoChao (String name, int life) {
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
