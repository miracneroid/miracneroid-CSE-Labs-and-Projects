class Animal {
    void speak() {
        System.out.println("Animal sound");
    }
}

class Dog extends Animal {
    @Override
    void speak() {
        System.out.println("Woof!");
    }
}

class Cat extends Animal {
    @Override
    void speak() {
        System.out.println("Meow!");
    }
}

public class main4 {
    public static void main(String[] args) {
        Animal animal = new Dog();
        animal.speak(); // Prints "Woof!"

        animal = new Cat();
        animal.speak(); // Prints "Meow!"
    }
}
