class StaticMethod {
  static void staticMethod() {
    System.out.println("This is a static method");
  }

  void nonStaticMethod() {
    System.out.println("This is a non-static method");
  }
}

public class main7 {
  public static void main(String[] args) {
    // Static method can be called without creating an object
    StaticMethod.staticMethod();

    // Non-static method cannot be called without creating an object
    // StaticMethod.nonStaticMethod();

    StaticMethod obj = new StaticMethod();
    obj.nonStaticMethod();
  }
}