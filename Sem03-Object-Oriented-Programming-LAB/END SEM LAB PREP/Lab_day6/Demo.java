public class Protection {
    public int pub;
    private int pri;
    protected int pro;
    int def;

    public Protection() {
        System.out.println("Public: " + pub);
        System.out.println("Private: " + pri);
        System.out.println("Protected: " + pro);
        System.out.println("Default: " + def);
    }
}

class Derived extends Protection {
    public void display() {
        System.out.println("Public: " + pub);
        System.out.println("Protected: " + pro);
        System.out.println("Default: " + def);
    }
}

class SamePackage {
    public void display() {
        Protection protection = new Protection();
        System.out.println("Public: " + protection.pub);
        System.out.println("Protected: " + protection.pro);
        System.out.println("Default: " + protection.def);
    }
}

class Demo {
    public Demo() {
        Protection protection = new Protection();
        Derived derived = new Derived();
        SamePackage samePackage = new SamePackage();

        System.out.println("Protection class:");
        protection.display();

        System.out.println("Derived class:");
        derived.display();

        System.out.println("Same package class:");
        samePackage.display();
    }

    public static void main(String[] args) {
        new Demo();
    }
}
