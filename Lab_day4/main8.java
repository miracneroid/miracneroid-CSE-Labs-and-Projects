class Apple {
    public void show() {
        System.out.println("I am an Apple");
    }
}

class Banana extends Apple {
    public void show() {
        System.out.println("I am a Banana");
    }
}

class Cherry extends Apple {
    public void show() {
        System.out.println("I am a Cherry");
    }
}

public class main8 {
    public static void main(String[] args) {
        Apple a = new Apple();
        a.show();

        Banana b = new Banana();
        b.show();

        Cherry c = new Cherry();
        c.show();
    }
}
