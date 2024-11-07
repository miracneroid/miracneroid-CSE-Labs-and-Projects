class Base {
  static {
    System.out.println("Static block of Base is executed");
  }

  void display() {
    System.out.println("This is a non-static method of Base");
  }
}

class Derived extends Base {
  static {
    System.out.println("Static block of Derived is executed");
  }

  void display() {
    System.out.println("This is a non-static method of Derived");
  }
}

public class main8 {
  public static void main(String[] args) {
    // Static block of Base is executed
    // Static block of Derived is executed
    Derived obj = new Derived();
    obj.display();
  }
}
