import java.util.Scanner;

public class main2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        try {
            String emptyString = new String();
            System.out.println("Empty String: \"" + emptyString + "\"");

            System.out.print("Enter a character array: ");
            char[] charArray = scanner.nextLine().toCharArray();
            String charArrayString = new String(charArray);
            System.out.println("Character Array String: \"" + charArrayString + "\"");

            System.out.print("Enter a character array: ");
            char[] offsetCharArray = scanner.nextLine().toCharArray();
            System.out.print("Enter the start index: ");
            int startIdx = scanner.nextInt();
            System.out.print("Enter the length: ");
            int length = scanner.nextInt();
            scanner.nextLine();
            String offsetCharArrayString = new String(offsetCharArray, startIdx, length);
            System.out.println("Offset Character Array String: \"" + offsetCharArrayString + "\"");

            System.out.print("Enter bytes (comma-separated): ");
            String bytesInput = scanner.nextLine();
            String[] byteStrings = bytesInput.split(",");
            byte[] bytes = new byte[byteStrings.length];
            for (int i = 0; i < byteStrings.length; i++) {
                bytes[i] = Byte.parseByte(byteStrings[i].trim());
            }
            String bytesString = new String(bytes);
            System.out.println("Bytes String: \"" + bytesString + "\"");

            System.out.print("Enter bytes (comma-separated) with encoding: ");
            bytesInput = scanner.nextLine();
            System.out.print("Enter the encoding (e.g., UTF-8): ");
            String encoding = scanner.nextLine();
            byteStrings = bytesInput.split(",");
            byte[] bytesWithEncoding = new byte[byteStrings.length];
            for (int i = 0; i < byteStrings.length; i++) {
                bytesWithEncoding[i] = Byte.parseByte(byteStrings[i].trim());
            }
            String bytesStringEncoding = new String(bytesWithEncoding, encoding);
            System.out.println("Bytes with Encoding String: \"" + bytesStringEncoding + "\"");

            System.out.print("Enter a string literal: ");
            String stringLiteral = scanner.nextLine();
            System.out.println("String Literal: \"" + stringLiteral + "\"");

            String stringObject = new String(stringLiteral);
            System.out.println("String Object: \"" + stringObject + "\"");
        } catch (Exception e) {
            System.err.println("An error occurred: " + e.getMessage());
        }
    }
}