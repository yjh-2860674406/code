package Java.ThreeKiller;

public class base {
    public class norkill extends poker {

        public norkill (int dian, Hua hua, String name) {
            super(dian, hua, name);
        }

        @Override
        public int skill(people me, people other) {
            other.hurted();
            return 1;
        }
    }

    public class flass extends poker {

        public flass(int dian, Hua hua, String name) {
            super(dian, hua, name);
        }

        @Override
        public int skill(people me, people other) {
            return 1;
        }
    }

    public class peach extends poker {
        public peach (int dian, Hua hua, String name) {
            super(dian, hua, name);
        }

        @Override
        public int skill(people me, people other) {
            other.cure();
            return 0;
        }
    }
}
