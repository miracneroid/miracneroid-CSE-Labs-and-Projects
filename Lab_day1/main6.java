public class main6{

    public static void main(String[] args) {
        if (args.length != 3) {
            System.out.println("Please provide two integer arguments.");
            return;
        }

        int num1 = Integer.parseInt(args[0]);
        int num2 = Integer.parseInt(args[1]);

        boolean continueProgram = true;

        while (continueProgram) {
            System.out.println("Choose an operation:");
            System.out.println("1. Addition");
            System.out.println("2. Subtraction");
            System.out.println("3. Multiplication");
            System.out.println("4. Division");
            System.out.println("5. Exit");
            
            // Assuming that user's choice is provided as the third argument
            int choice = Integer.parseInt(args[2]);

            switch (choice) {
                case 1:
                    System.out.println("Addition: " + (num1 + num2));
                    break;
                case 2:
                    System.out.println("Subtraction: " + (num1 - num2));
                    break;
                case 3:
                    System.out.println("Multiplication: " + (num1 * num2));
                    break; 
                case 4:
                    if (num2 != 0) {
                        System.out.println("Division: " + ((double) num1 / num2));
                    } else {
                        System.out.println("Cannot divide by zero.");
                    }
                    break;
                case 5:
                    continueProgram = false;
                    break;
                default:
                    System.out.println("Invalid choice.");
            }
            
            // Assuming that user's choice of whether to continue is provided as the fourth argument
            int continueChoice = Integer.parseInt(args[3]);
            
            if (continueChoice != 1) {
                continueProgram = false;
            }
        }
    }
}
