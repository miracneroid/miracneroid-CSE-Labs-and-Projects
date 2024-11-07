class StaticVariable {
  static int staticVariable = 10;

  void displayStaticVariable() {
    System.out.println("Static variable: " + staticVariable);
  }
}

public class main6 {
  public static void main(String[] args) {
    // Static variable can be accessed without creating an object
    System.out.println("Static variable: " + StaticVariable.staticVariable);

    StaticVariable obj1 = new StaticVariable();
    obj1.displayStaticVariable();

    StaticVariable obj2 = new StaticVariable();
    obj2.displayStaticVariable();
  }
}