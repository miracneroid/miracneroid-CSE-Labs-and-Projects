/*
2. Create two files, write a date in the first file and Using FileReader and FileWriter(char by char) - copy the date of one file to another file.
*/

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class main2 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        try {
            System.out.print("Enter a date to write to the first file: ");
            String inputDate = scanner.nextLine();

            try (FileWriter writer = new FileWriter("file1.txt")) {
                writer.write(inputDate);
            }

            System.out.println("Date has been written to file1.txt\n");

            try (FileReader fileReader = new FileReader("file1.txt")) {
                int character;
                System.out.println("Content of file1.txt:");
                while ((character = fileReader.read()) != -1) {
                    System.out.print((char) character);
                }
                System.out.println("\n");
            }

            try (FileReader fileReader = new FileReader("file1.txt");
                 FileWriter fileWriter = new FileWriter("file2.txt")) {

                int character;
                System.out.println("Copying content from file1.txt to file2.txt:");

                while ((character = fileReader.read()) != -1) {
                    fileWriter.write(character);
                    System.out.print((char) character);
                }
                System.out.println("\n");
            }

            try (FileReader fileReader = new FileReader("file2.txt")) {
                int character;
                System.out.println("Content of file2.txt:");
                while ((character = fileReader.read()) != -1) {
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
