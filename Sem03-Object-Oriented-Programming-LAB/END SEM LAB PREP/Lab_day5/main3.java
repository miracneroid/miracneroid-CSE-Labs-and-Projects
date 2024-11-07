class Shape {
    double area;

    void showArea() {
        System.out.println("Area of the shape is: " + area);
    }
}

class Circle extends Shape {
    double radius;

    Circle(double radius) {
        this.radius = radius;
    }

    void calculateArea() {
        area = Math.PI * radius * radius;
    }
}

class Rectangle extends Shape {
    double length;
    double breadth;

    Rectangle(double length, double breadth) {
        this.length = length;
        this.breadth = breadth;
    }

    void calculateArea() {
        area = length * breadth;
    }
}

public class Main {
    public static void main(String[] args) {
        Circle circle = new Circle(5);
        circle.calculateArea();
        circle.showArea();

        Rectangle rectangle = new Rectangle(10, 5);
        rectangle.calculateArea();
        rectangle.showArea();
    }
}
