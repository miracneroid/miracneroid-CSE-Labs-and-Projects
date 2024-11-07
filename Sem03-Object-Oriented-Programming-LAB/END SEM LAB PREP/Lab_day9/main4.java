/*
3. RandomAccess file - using rw permission, writer some data to the file and read the same and display on monitor, here u use the function writeChar(), writeInt(), writerBoolean()....
*/

import java.io.RandomAccessFile;

public class main4 {

    public static void main(String[] args) {
        try {
            RandomAccessFile file = new RandomAccessFile("random_access_file.dat", "rw");

            // Writing data to the file
            file.writeChar('A');
            file.writeInt(123);
            file.writeBoolean(true);

            file.seek(0);

            char charValue = file.readChar();
            int intValue = file.readInt();
            boolean boolValue = file.readBoolean();

            System.out.println("Read and Display Data:");
            System.out.println("Char: " + charValue);
            System.out.println("Int: " + intValue);
            System.out.println("Boolean: " + boolValue);

            file.close();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
