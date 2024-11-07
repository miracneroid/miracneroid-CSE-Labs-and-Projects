/*
7. Write a java program to capitalize first letter of every word in a file.
*/

import java.io.*;

public class main7 {

    public static void main(String[] args) {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        try {
            // Taking input from the user for the file name
            System.out.print("Enter the file name: ");
            String fileName = reader.readLine();

            // Capitalizing the first letter of every word in the file
            capitalizeWordsInFile(fileName);

            // Reading and displaying the modified content of the file
            String modifiedContent = readFile(fileName);
            System.out.println("\nModified content of the file:");
            System.out.println(modifiedContent);

        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                reader.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    private static void capitalizeWordsInFile(String fileName) {
        try (BufferedReader fileReader = new BufferedReader(new FileReader(fileName));
             BufferedWriter fileWriter = new BufferedWriter(new FileWriter("modified_" + fileName))) {

            String line;
            while ((line = fileReader.readLine()) != null) {
                // Capitalize the first letter of each word
                String[] words = line.split("\\s+");
                for (String word : words) {
                    if (word.length() > 0) {
                        word = Character.toUpperCase(word.charAt(0)) + word.substring(1);
                        fileWriter.write(word + " ");
                    }
                }
                fileWriter.newLine();
            }

            System.out.println("File content has been modified.");

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static String readFile(String fileName) {
        StringBuilder content = new StringBuilder();

        try (BufferedReader fileReader = new BufferedReader(new FileReader("modified_" + fileName))) {
            String line;
            while ((line = fileReader.readLine()) != null) {
                content.append(line).append("\n");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        return content.toString();
    }
}
