public class main6 {
    public static void main(String[] args) {
        try {
            System.out.println("Outer try block entered.");

            try {
                System.out.println("Inner try block entered.");

                int[] arr = new int[5];
                arr[5] = 10;

            } catch (ArrayIndexOutOfBoundsException e) {
                System.out.println("ArrayIndexOutOfBoundsException caught in inner try block.");
                e.printStackTrace();
            }

            System.out.println("Inner try block exited.");
        } catch (Exception e) {
            System.out.println("Exception caught in outer try block.");
            e.printStackTrace();
        }

        System.out.println("Outer try block exited.");
    }
