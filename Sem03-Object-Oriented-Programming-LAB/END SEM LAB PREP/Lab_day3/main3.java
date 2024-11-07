import java.util.Scanner;

public class main3 {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    // Get the number of rows and columns
    System.out.println("Enter the number of rows: ");
    int rows = sc.nextInt();
    System.out.println("Enter the number of columns: ");
    int cols = sc.nextInt();

    // Create a 2D array
    int[][] arr = new int[rows][cols];

    // Get the elements of the array from the user
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        System.out.println("Enter the value at row " + i + ", column " + j + ": ");
        arr[i][j] = sc.nextInt();
      }
    }

    // Print the 2D array in matrix form
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        System.out.print(arr[i][j] + " ");
      }
      System.out.println();
    }
  }
}
