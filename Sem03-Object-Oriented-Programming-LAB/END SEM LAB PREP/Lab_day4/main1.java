import java.util.Scanner;

class Box {
    private double length;
    private double width;
    private double height;

    public Box(double length, double width, double height) {
        this.length = length;
        this.width = width;
        this.height = height;
    }

    public double volume() {
        return length * width * height;
    }
}

public class main1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        
        System.out.print("Enter the length of the box: ");
        double length = scanner.nextDouble();

        System.out.print("Enter the width of the box: ");
        double width = scanner.nextDouble();

        System.out.print("Enter the height of the box: ");
        double height = scanner.nextDouble();

        
        Box myBox = new Box(length, width, height);

       
        double boxVolume = myBox.volume();
        System.out.println("The volume of the box is: " + boxVolume);
        
        scanner.close();
    }
}
