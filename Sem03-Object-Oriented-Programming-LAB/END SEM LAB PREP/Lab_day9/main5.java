/*
5. Using sequenceINputStream read two file parallely and writer to the third fil;e, again read from the third file and display on the monitor
*/

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.SequenceInputStream;
import java.util.Collections;
import java.util.Enumeration;
import java.util.Vector;

public class main5 {

    public static void main(String[] args) {
        try {
            FileInputStream file1 = new FileInputStream("file1.txt");
            FileInputStream file2 = new FileInputStream("file2.txt");

            Vector<FileInputStream> vector = new Vector<>();
            vector.add(file1);
            vector.add(file2);

            Enumeration<FileInputStream> files = vector.elements();

            SequenceInputStream sequenceInputStream = new SequenceInputStream(files);

            FileOutputStream mergedFile = new FileOutputStream("merged_file.txt");

            int byteRead;
            while ((byteRead = sequenceInputStream.read()) != -1) {
                mergedFile.write(byteRead);

                if (sequenceInputStream.available() == 0) {
                    mergedFile.write('\n');
                }
            }

            System.out.println("Files merged successfully to merged_file.txt");

            sequenceInputStream.close();
            mergedFile.close();

            try (FileInputStream mergedFileInput = new FileInputStream("merged_file.txt")) {
                System.out.println("\nContent of merged_file.txt:");
                while ((byteRead = mergedFileInput.read()) != -1) {
                    System.out.print((char) byteRead);
                }
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
