import java.util.Scanner;

class Rectangle {
    private double length;
    private double breadth;

   
    public Rectangle() {
        length = 0;
        breadth = 0;
    }

    
    public Rectangle(double length, double breadth) {
        this.length = length;
        this.breadth = breadth;
    }

    public double calculateArea() {
        return length * breadth;
    }
}

public class main3 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        
        Rectangle defaultRectangle = new Rectangle();

        
        System.out.print("Enter the length of the rectangle: ");
        double length = scanner.nextDouble();
        System.out.print("Enter the breadth of the rectangle: ");
        double breadth = scanner.nextDouble();

        
        Rectangle userRectangle = new Rectangle(length, breadth);

        
        double areaDefault = defaultRectangle.calculateArea();
        double areaUser = userRectangle.calculateArea();

        System.out.println("Area of default rectangle: " + areaDefault);
        System.out.println("Area of user-defined rectangle: " + areaUser);

        scanner.close();
    }
}
