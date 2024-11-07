/*
 *1) Program to print the corresponding week day for the given day no of the current month using switch. case statement in Java.
 */

import java.util.Scanner;

public class main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the year: ");
        int year = scanner.nextInt();
        
        System.out.print("Enter the month (1-12): ");
        int month = scanner.nextInt();
        
        System.out.print("Enter the day of the month: ");
        int day = scanner.nextInt();
        
        int k = day;
        int m = month;
        int y = year; 
        int D = y % 100;
        int C = y / 100;

        /*
         * Zeller's Congruence Algorithm. 
         * 
         * Zeller's Congruence is a mathematical formula developed by Christian Zeller in the 19th century for calculating the day of the week for any date in the Gregorian calendar.
         */
        
        int f = k + ((13 * (m + 1)) / 5) + D + (D / 4) + (C / 4) - (2 * C);
        
        int dayOfWeek = (f % 7 + 7) % 7;
        
        switch (dayOfWeek) {
            case 0:
                System.out.println("Saturday");
                break;
            case 1:
                System.out.println("Sunday");
                break;
            case 2:
                System.out.println("Monday");
                break;
            case 3:
                System.out.println("Tuesday");
                break;
            case 4:
                System.out.println("Wednesday");
                break;
            case 5:
                System.out.println("Thursday");
                break;
            case 6:
                System.out.println("Friday");
                break;
            default:
                System.out.println("Invalid day");
        }
        
        scanner.close();
    }
}
