/*
use the functionality of DataInput and DOS, and PrintStream
*/

import java.io.*;

public class main9 {

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
        try (DataOutputStream dataOutputStream = new DataOutputStream(new FileOutputStream(fileName))) {
            dataOutputStream.write(data);
            System.out.println("Data has been written to " + fileName);
        }
    }

    private static void compareBinaryFiles(String file1, String file2) throws IOException {
        try (DataInputStream dataInputStream1 = new DataInputStream(new FileInputStream(file1));
             DataInputStream dataInputStream2 = new DataInputStream(new FileInputStream(file2))) {

            int position = 0;
            byte byte1, byte2;

            while (true) {
                try {
                    byte1 = dataInputStream1.readByte();
                    byte2 = dataInputStream2.readByte();

                    if (byte1 != byte2) {
                        System.out.println("Files differ at position: " + position);
                        return;
                    }
                    position++;
                } catch (EOFException e) {
                    break;
                }
            }

            try {
                dataInputStream1.readByte();
                dataInputStream2.readByte();
                System.out.println("Files differ at position: " + position);
            } catch (EOFException e) {
                System.out.println("Files are identical.");
            }
        }
    }
}
