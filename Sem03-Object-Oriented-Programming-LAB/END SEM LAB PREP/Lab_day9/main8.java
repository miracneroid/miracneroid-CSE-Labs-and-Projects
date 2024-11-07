/*
Write a java program to compare two binary files, printing the first byte position where they differ.
*/

import java.io.*;

public class main8 {

    public static void main(String[] args) {
        try {
            createBinaryFile("file1.bin", new byte[]{1, 2, 3, 4, 5});
            createBinaryFile("file2.bin", new byte[]{1, 2, 3, 9, 5});

            compareBinaryFiles("file1.bin", "file2.bin");

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static void createBinaryFile(String fileName, byte[] data) throws IOException {
        try (FileOutputStream fileOutputStream = new FileOutputStream(fileName)) {
            fileOutputStream.write(data);
            System.out.println("Data has been written to " + fileName);
        }
    }

    private static void compareBinaryFiles(String file1, String file2) throws IOException {
        try (FileInputStream inputStream1 = new FileInputStream(file1);
             FileInputStream inputStream2 = new FileInputStream(file2)) {

            int position = 0;
            int byte1, byte2;

            while ((byte1 = inputStream1.read()) != -1 && (byte2 = inputStream2.read()) != -1) {
                if (byte1 != byte2) {
                    System.out.println("Files differ at position: " + position);
                    return;
                }
                position++;
            }
            if (inputStream1.read() != inputStream2.read()) {
                System.out.println("Files differ at position: " + position);
            } else {
                System.out.println("Files are identical.");
            }

        }
    }
}
