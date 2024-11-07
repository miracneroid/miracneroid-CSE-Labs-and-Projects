import java.util.Scanner;

public class main1 {
    public static void checkNumber(int number) {
        if (number <= 0 || number >= 100) {
            throw new IllegalArgumentException("Number must be greater than or equal to 0 and less than or equal to 100");
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a number: ");
        int numberToCheck = scanner.nextInt();

        try {
            checkNumber(numberToCheck);
            System.out.println("The number is within the range.");
        } catch (IllegalArgumentException e) {
            System.err.println("Invalid number: " + e.getMessage());
        }

        scanner.close();
    }
}
