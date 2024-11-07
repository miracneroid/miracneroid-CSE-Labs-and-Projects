import java.util.Scanner;

// 2D Sheet Class
class TwoDimensional {
    protected double length;
    protected double width;

    public TwoDimensional(double length, double width) {
        this.length = length;
        this.width = width;
    }

    public double calculateCost() {
        return length * width * 40; 
    }
}

// 3D Box Class
class ThreeDimensional extends TwoDimensional {
    protected double height;

    public ThreeDimensional(double length, double width, double height) {
        super(length, width);
        this.height = height;
    }

    public double calculateCost() {
        return super.calculateCost() + length * width * height * 60; // Rs 60 per cubic ft
    }
}

public class main6{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Select the plastic shape:");
        System.out.println("1. 2D Sheet");
        System.out.println("2. 3D Box");
        System.out.print("Enter your choice: ");
        int choice = scanner.nextInt();

        if (choice == 1) {
            System.out.print("Enter the length (in ft): ");
            double length = scanner.nextDouble();
            System.out.print("Enter the width (in ft): ");
            double width = scanner.nextDouble();

            TwoDimensional sheet = new TwoDimensional(length, width);
            double cost = sheet.calculateCost();
            System.out.println("Cost of the 2D sheet: Rs " + cost);
        } else if (choice == 2) {
            System.out.print("Enter the length (in ft): ");
            double length = scanner.nextDouble();
            System.out.print("Enter the width (in ft): ");
            double width = scanner.nextDouble();
            System.out.print("Enter the height (in ft): ");
            double height = scanner.nextDouble();

            ThreeDimensional box = new ThreeDimensional(length, width, height);
            double cost = box.calculateCost();
            System.out.println("Cost of the 3D box: Rs " + cost);
        } else {
            System.out.println("Invalid choice.");
        }

        scanner.close();
    }
}
