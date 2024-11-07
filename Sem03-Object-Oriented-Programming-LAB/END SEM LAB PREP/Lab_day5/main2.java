class Base {
    int x;

    Base(int x) {
        this.x = x;
    }

    void disp() {
        System.out.println("x = " + x);
    }
}

class Derived extends Base {
    int y;

    Derived(int x, int y) {
        super(x);
        this.y = y;
    }

    void disp() {
        super.disp();
        System.out.println("y = " + y);
    }
}

public class main2 {
    public static void main(String[] args) {
        Derived derived = new Derived(10, 20);
        derived.disp();
    }
}
