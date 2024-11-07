/*
1. Using FIS and FOS - read Stu roll no and name from key board, then write to a file, then open the file read the date and display on the monitor
*/

import java.io.*;

public class main1 {

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            System.out.print("Enter student roll number: ");
            int rollNumber = Integer.parseInt(br.readLine());

            System.out.print("Enter student name: ");
            String name = br.readLine();

            try (FileOutputStream fos = new FileOutputStream("student.txt")) {
                String data = rollNumber + "," + name;
                fos.write(data.getBytes());
                System.out.println("Data written to file successfully.");
            } catch (IOException e) {
                e.printStackTrace();
            }

            try (FileInputStream fis = new FileInputStream("student.txt")) {
                int content;
                StringBuilder fileContent = new StringBuilder();
                while ((content = fis.read()) != -1) {
                    fileContent.append((char) content);
                }

                String[] studentData = fileContent.toString().split(",");
                int storedRollNumber = Integer.parseInt(studentData[0]);
                String storedName = studentData[1];

                System.out.println("\nData read from file:");
                System.out.println("Roll Number: " + storedRollNumber);
                System.out.println("Name: " + storedName);

            } catch (IOException e) {
                e.printStackTrace();
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
