public class main8 {
    public static void main(String[] args) {
        if (args.length != 3) {
            System.out.println("Please provide three numbers.");
            return;
        }
        
        try {
            double num1 = Double.parseDouble(args[0]);
            double num2 = Double.parseDouble(args[1]);
            double num3 = Double.parseDouble(args[2]);
            
            double largest = num1;

            if (num2 > largest) {
                largest = num2;
            }

            if (num3 > largest) {
                largest = num3;
            }

            System.out.println("Largest number: " + largest);

            if (num1 == num2 && num2 == num3) {
                System.out.println("All three numbers are equal.");
            } else if (num1 == num2 || num1 == num3 || num2 == num3) {
                System.out.println("At least two numbers are equal.");
            } else {
                System.out.println("All three numbers are different.");
            }

        } catch (NumberFormatException e) {
            System.out.println("Invalid input. Please provide valid numerical values.");
        }
    }
}