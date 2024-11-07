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

class main6 {
    public static void main(String[] args) {
        Circle circle = new Circle(5);
        Rectangle rectangle = new Rectangle(10, 5);

        System.out.println("Area of circle: " + circle.calcArea());
        System.out.println("Area of rectangle: " + rectangle.calcArea());
    }
}
