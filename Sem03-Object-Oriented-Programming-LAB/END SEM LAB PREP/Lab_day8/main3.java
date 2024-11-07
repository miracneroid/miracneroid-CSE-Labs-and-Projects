import java.util.Scanner;

public class main3 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        try {
            // Input a string from the user
            System.out.print("Enter a string: ");
            String inputString = scanner.nextLine();

            // Create a StringBuilder from the input string
            StringBuilder stringBuilder = new StringBuilder(inputString);

            // Append a string
            System.out.print("Enter a string to append: ");
            String appendString = scanner.nextLine();
            stringBuilder.append(appendString);
            System.out.println("Appended string: " + stringBuilder);

            // Insert a string at a specific index
            System.out.print("Enter an index to insert a string: ");
            int insertIndex = scanner.nextInt();
            scanner.nextLine(); // Consume the newline character
            System.out.print("Enter a string to insert: ");
            String insertString = scanner.nextLine();
            stringBuilder.insert(insertIndex, insertString);
            System.out.println("Inserted string: " + stringBuilder);

            // Delete a range of characters
            System.out.print("Enter the start index to delete: ");
            int startIndex = scanner.nextInt();
            System.out.print("Enter the end index to delete: ");
            int endIndex = scanner.nextInt();
            stringBuilder.delete(startIndex, endIndex);
            System.out.println("String after deletion: " + stringBuilder);

            // Reverse the string
            stringBuilder.reverse();
            System.out.println("Reversed string: " + stringBuilder);
        } catch (Exception e) {
            System.err.println("An error occurred: " + e.getMessage());
        } finally {
            scanner.close();
        }
    }
}
