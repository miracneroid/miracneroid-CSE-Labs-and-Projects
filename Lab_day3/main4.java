import java.util.Scanner;

class Customer {
  int custlD;
  String custName;
  int custAge;

  void acceptDetails() {
    Scanner sc = new Scanner(System.in);

    System.out.println("Enter customer ID: ");
    custlD = sc.nextInt();

    System.out.println("Enter customer name: ");
    custName = sc.next();

    System.out.println("Enter customer age: ");
    custAge = sc.nextInt();
  }

  void displayDetails() {
    System.out.println("Customer ID: " + custlD);
    System.out.println("Customer name: " + custName);
    System.out.println("Customer age: " + custAge);
  }
}

public class main4 extends Customer {

  public static void main(String[] args) {
    Customer[] customers = new Customer[3];

    for (int i = 0; i < customers.length; i++) {
      customers[i] = new Customer();
      customers[i].acceptDetails();
    }

    System.out.println("Customer details:");
    for (int i = 0; i < customers.length; i++) {
      customers[i].displayDetails();
    }
  }
}
