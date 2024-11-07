import java.util.Scanner;

class Plate {
    protected double length;
    protected double width;

    public Plate(double length, double width) {
        this.length = length;
        this.width = width;
        System.out.println("Plate constructor called");
    }
}

class Box extends Plate {
    protected double height;

    public Box(double length, double width, double height) {
        super(length, width); 
        this.height = height;
        System.out.println("Box constructor called");
    }
}

class WoodBox extends Box {
    protected double thickness;

    public WoodBox(double length, double width, double height, double thickness) {
        super(length, width, height); 
        this.thickness = thickness;
        System.out.println("WoodBox constructor called");
    }

    public void displayDimensions() {
        System.out.println("Dimensions: " +
                "Length=" + length +
                ", Width=" + width +
                ", Height=" + height +
                ", Thickness=" + thickness);
    }
}

public class main7 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter length for Plate: ");
        double plateLength = scanner.nextDouble();
        System.out.print("Enter width for Plate: ");
        double plateWidth = scanner.nextDouble();

        System.out.print("Enter length for Box: ");
        double boxLength = scanner.nextDouble();
        System.out.print("Enter width for Box: ");
        double boxWidth = scanner.nextDouble();
        System.out.print("Enter height for Box: ");
        double boxHeight = scanner.nextDouble();

        System.out.print("Enter length for WoodBox: ");
        double woodBoxLength = scanner.nextDouble();
        System.out.print("Enter width for WoodBox: ");
        double woodBoxWidth = scanner.nextDouble();
        System.out.print("Enter height for WoodBox: ");
        double woodBoxHeight = scanner.nextDouble();
        System.out.print("Enter thickness for WoodBox: ");
        double woodBoxThickness = scanner.nextDouble();

        WoodBox myWoodBox = new WoodBox(woodBoxLength, woodBoxWidth, woodBoxHeight, woodBoxThickness);
        myWoodBox.displayDimensions();

        scanner.close();
    }
}
