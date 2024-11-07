import p1.Protection;

public class Protection2 extends Protection {
    public void display() {
        System.out.println("Public: " + pub);
        System.out.println("Protected: " + pro);
    }
}

class OtherPackage {
    public OtherPackage() {
        Protection2 protection2 = new Protection2();

        System.out.println("Protection2 class:");
        protection2.display();
    }
}

class Demo2 {
    public Demo2() {
        Protection2 protection2 = new Protection2();
        OtherPackage otherPackage = new OtherPackage();

        System.out.println("Protection2 class:");
        protection2.display();

        System.out.println("Other package class:");
        otherPackage.display();
    }

    public static void main(String[] args) {
        new Demo2();
    }
}
