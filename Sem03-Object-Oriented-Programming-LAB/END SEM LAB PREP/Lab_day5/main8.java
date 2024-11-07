class main8 {
    void makeSound() {
        System.out.println("Animal sound");
    }
}

class Dog extends main8 {
    @Override
    void makeSound() {
        super.makeSound(); // Call the superclass method
        System.out.println("Woof!");
    }
}
