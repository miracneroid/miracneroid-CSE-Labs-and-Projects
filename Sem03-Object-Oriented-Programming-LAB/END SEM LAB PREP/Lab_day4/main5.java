import java.util.Scanner;

class AreaCalculator {
   
    public double area(double radius) {
        return Math.PI * radius * radius;
    }

    
    public double area(double base, double height) {
        return 0.5 * base * height;
    }

    
    public double area(double sideLength, int choice) {
        if (choice == 3) {
            return sideLength * sideLength;
        }
        return 0.0;
    }
}

public class main5 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        AreaCalculator calculator = new AreaCalculator();

        int choice;
        do {
            System.out.println("Menu:");
            System.out.println("1. Calculate the area of a circle");
            System.out.println("2. Calculate the area of a triangle");
            System.out.println("3. Calculate the area of a square");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter the radius of the circle: ");
                    double radius = scanner.nextDouble();
                    double circleArea = calculator.area(radius);
                    System.out.println("Area of the circle: " + circleArea);
                    break;
                case 2:
                    System.out.print("Enter the base of the triangle: ");
                    double base = scanner.nextDouble();
                    System.out.print("Enter the height of the triangle: ");
                    double height = scanner.nextDouble();
                    double triangleArea = calculator.area(base, height);
                    System.out.println("Area of the triangle: " + triangleArea);
                    break;
                case 3:
                    System.out.print("Enter the side length of the square: ");
                    double sideLength = scanner.nextDouble();
                    double squareArea = calculator.area(sideLength, choice);
                    System.out.println("Area of the square: " + squareArea);
                    break;
                case 4:
                    System.out.println("Exiting the program. Goodbye!");
                    break;
                default:
                    System.out.println("Invalid choice. Please enter a valid option.");
            }
        } while (choice != 4);

        scanner.close();
    }
}
