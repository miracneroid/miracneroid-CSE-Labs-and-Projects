/*
 * WAP in java which will accept N numbers(N will be taken from keyboard as per user choce) and will display the total number of even, total number of odd, sum of even, sum of odd and the GRAND TOTAL - use (InputStream Reader and BufferedReader)
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class main4 {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        System.out.print("Enter the value of N: ");
        int N = Integer.parseInt(reader.readLine());

        int evenCount = 0;
        int oddCount = 0;
        int evenSum = 0;
        int oddSum = 0;
        int grandTotal = 0;

        for (int i = 1; i <= N; i++) {
            System.out.print("Enter number " + i + ": ");
            int num = Integer.parseInt(reader.readLine());
            grandTotal += num;

            if (num % 2 == 0) {
                evenCount++;
                evenSum += num;
            } else {
                oddCount++;
                oddSum += num;
            }
        }

        System.out.println("Total number of even numbers: " + evenCount);
        System.out.println("Total number of odd numbers: " + oddCount);
        System.out.println("Sum of even numbers: " + evenSum);
        System.out.println("Sum of odd numbers: " + oddSum);
        System.out.println("Grand Total: " + grandTotal);

        reader.close();
    }
}
