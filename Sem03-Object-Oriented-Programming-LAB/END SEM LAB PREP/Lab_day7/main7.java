public class main7 {
    public static void main(String[] args) {

        try {
            int[] array = new int[5];
            array[5] = 10;

            String string = null;
            string.length();

            int result = 15 / 0;
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("ArrayIndexOutOfBoundsException occurred: " + e.getMessage());
        } catch (NullPointerException e) {
            System.out.println("NullPointerException occurred: " + e.getMessage());
        } catch (ArithmeticException e) {
            System.out.println("ArithmeticException occurred: " + e.getMessage());
        }

        try {
            int[] array = new int[5];
            array[5] = 10;
        } catch (ArrayIndexOutOfBoundsException | NullPointerException e) {
            System.out.println(e.getMessage());
        }

        finally {
            System.out.println("This code will always be executed, regardless of whether an exception is thrown or not.");
        }
    }
}