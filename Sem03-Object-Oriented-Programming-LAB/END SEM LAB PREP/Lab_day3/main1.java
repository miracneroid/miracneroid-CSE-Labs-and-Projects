import java.io.*;

class Student {
  String name;
  int rollNo;
  int marks1, marks2, marks3, marks4;

  void acceptDetails() throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    System.out.println("Enter student name: ");
    name = br.readLine();

    System.out.println("Enter student roll number: ");
    rollNo = Integer.parseInt(br.readLine());

    System.out.println("Enter marks of subject 1: ");
    marks1 = Integer.parseInt(br.readLine());

    System.out.println("Enter marks of subject 2: ");
    marks2 = Integer.parseInt(br.readLine());

    System.out.println("Enter marks of subject 3: ");
    marks3 = Integer.parseInt(br.readLine());

    System.out.println("Enter marks of subject 4: ");
    marks4 = Integer.parseInt(br.readLine());
  }

  void displayDetails() {
    System.out.println("Student name: " + name);
    System.out.println("Student roll number: " + rollNo);
    System.out.println("Marks of subject 1: " + marks1);
    System.out.println("Marks of subject 2: " + marks2);
    System.out.println("Marks of subject 3: " + marks3);
    System.out.println("Marks of subject 4: " + marks4);

    int totalMarks = marks1 + marks2 + marks3 + marks4;
    float percentage = (totalMarks / 400) * 100;

    String grade;
    if (percentage >= 90) {
      grade = "A+";
    } else if (percentage >= 80) {
      grade = "A";
    } else if (percentage >= 70) {
      grade = "B";
    } else if (percentage >= 60) {
      grade = "C";
    } else if (percentage >= 50) {
      grade = "D";
    } else {
      grade = "F";
    }

    System.out.println("Grade: " + grade);
  }
}

public class main1 {
  public static void main(String[] args) throws IOException {
    Student student = new Student();
    student.acceptDetails();
    student.displayDetails();
  }
}