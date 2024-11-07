/*
3. Create two files, write a date in the first file and Using FIS and FOS(char by char) - copy the date of one file to another file.
*/

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Scanner;

public class main3 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        try {
            System.out.print("Enter a date to write to the first file: ");
            String inputDate = scanner.nextLine();

            try (FileOutputStream fos = new FileOutputStream("file1.txt")) {
                for (char c : inputDate.toCharArray()) {
                    fos.write(c);
                }
            }

            System.out.println("Date has been written to file1.txt\n");

            try (FileInputStream fis = new FileInputStream("file1.txt")) {
                int character;
                System.out.println("Content of file1.txt:");
                while ((character = fis.read()) != -1) {
                    System.out.print((char) character);
                }
                System.out.println("\n");
            }

            try (FileInputStream fis = new FileInputStream("file1.txt");
                 FileOutputStream fos = new FileOutputStream("file2.txt")) {

                int character;
                System.out.println("Copying content from file1.txt to file2.txt:");

                while ((character = fis.read()) != -1) {
                    fos.write(character);
                    System.out.print((char) character);
                }
                System.out.println("\n");
            }

            try (FileInputStream fis = new FileInputStream("file2.txt")) {
                int character;
                System.out.println("Content of file2.txt:");
                while ((character = fis.read()) != -1) {
                    System.out.print((char) character);
                }
            }

        } catch (IOException e) {
            System.err.println("Error: " + e.getMessage());
        } finally {
            scanner.close();
        }
    }
}
