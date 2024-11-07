public class main2 {

  public static void main(String[] args) {
    int a = 5;
    int b = 7;

    // Bitwise AND operator
    System.out.println("a & b = " + (a & b)); // 5

    // Bitwise OR operator
    System.out.println("a | b = " + (a | b)); // 7

    // Bitwise XOR operator
    System.out.println("a ^ b = " + (a ^ b)); // 2

    // Bitwise NOT operator
    System.out.println("~a = " + (~a)); // -6

    // Ternary operator
    int max = (a > b) ? a : b;
    System.out.println("Max value is: " + max); // 7
  }
}
