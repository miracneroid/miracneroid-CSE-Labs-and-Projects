public class main4 {
    public static void main(String[] args) {
        try {
            int[] arr = new int[5];
            arr[5] = 10;
        } catch (ArithmeticException e) {
            System.out.println("ArithmeticException occurred");
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("ArrayIndexOutOfBoundsException occurred");
        } catch (Exception e) {
            System.out.println("Exception occurred: " + e.getMessage());
        }
        System.out.println("Rest of the code");
    }
}