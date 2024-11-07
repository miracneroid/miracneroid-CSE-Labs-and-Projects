public class main2 {

    public static void main(String[] args) {

        int[] arr = null;

        try {
            System.out.println(arr[0]);
        } catch (NullPointerException e) {
            System.out.println("Caught NullPointerException: " + e.getMessage());
        }
    }
}