public class main1 {
    public static void main(String[] args) {

        try {
            int result = 10 / 0;
        } catch (ArithmeticException e) {

            System.out.println("ArithmeticException occurred: " + e.getMessage());
        }
    }
}