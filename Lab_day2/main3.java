/*
 * Write a program in Java to take first name and last name from user and print both in one line as last name followed by first name.
 */

import java.util.Scanner;

public class main3 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter your first name: ");
        String firstName = scanner.nextLine();

        System.out.print("Enter your last name: ");
        String lastName = scanner.nextLine();

        String fullName = lastName + " " + firstName;
        System.out.println("Full name (last name followed by first name): " + fullName);

        scanner.close();
    }
}