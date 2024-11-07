import java.util.Scanner;

class Account {
    int acc_no;
    double balance;

    void input() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter account number: ");
        acc_no = sc.nextInt();
        System.out.println("Enter balance: ");
        balance = sc.nextDouble();
    }

    void disp() {
        System.out.println("Account number: " + acc_no);
        System.out.println("Balance: " + balance);
    }
}

class Person extends Account {
    String name;
    long aadhar_no;

    @Override
    void disp() {
        super.disp();
        System.out.println("Name: " + name);
        System.out.println("Aadhar number: " + aadhar_no);
    }
}

public class main1 {
    public static void main(String[] args) {
        Person[] persons = new Person[3];
        for (int i = 0; i < 3; i++) {
            persons[i] = new Person();
            persons[i].input();
        }

        for (int i = 0; i < 3; i++) {
            persons[i].disp();
        }
    }
}
