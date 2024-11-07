/*
 * Declare an integer array of size 10 with value and display the same using for each loop
 */

public class main5 {
    public static void main(String[] args) {
        int[] numbers = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };

        System.out.println("Array values:");
        for (int number : numbers) {
            System.out.println(number);
        }
    }
}
