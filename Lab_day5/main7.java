abstract class Shape {
    abstract double calcArea();
}

class Circle extends Shape {
    double radius;

    Circle(double radius) {
        this.radius = radius;
    }

    @Override
    double calcArea() {
        return Math.PI * radius * radius;
    }
}

class Rectangle extends Shape {
    double length;
    double breadth;

    Rectangle(double length, double breadth) {
        this.length = length;
        this.breadth = breadth;
    }

    @Override
    double calcArea() {
        return length * breadth;
    }
}

class main7 {
    public static void main(String[] args) {
        Shape shape; // Reference object of Shape class

        // Initialize the Shape object with a Circle object
        shape = new Circle(5);
        System.out.println("Area of circle: " + shape.calcArea());

        // Initialize the Shape object with a Rectangle object
        shape = new Rectangle(10, 5);
        System.out.println("Area of rectangle: " + shape.calcArea());
    }
}
