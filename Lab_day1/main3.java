public class main3 {

    public static void main(String[] args) {
        if (args.length < 2) {
            System.out.println("Please provide two numbers as command-line arguments.");
            return;
        }

        // Convert the command-line arguments to integers
        int num1 = Integer.parseInt(args[0]);
        int num2 = Integer.parseInt(args[1]);

        // Add the two numbers together
        int sum = num1 + num2;

        // Print the sum to the console
        System.out.println("The sum of the two numbers is: " + sum);
    }
}