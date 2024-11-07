public class main4{
    public static void main(String[] args) {
        if (args.length == 0) {
            System.out.println("No numbers provided.");
            return;
        }

        int totalEven = 0;
        int totalOdd = 0;
        int sumEven = 0;
        int sumOdd = 0;

        for (String arg : args) {
            int num = Integer.parseInt(arg);
            if (num % 2 == 0) {
                totalEven++;
                sumEven += num;
            } else {
                totalOdd++;
                sumOdd += num;
            }
        }

        int grandTotal = totalEven + totalOdd;

        System.out.println("Total even numbers: " + totalEven);
        System.out.println("Total odd numbers: " + totalOdd);
        System.out.println("Sum of even numbers: " + sumEven);
        System.out.println("Sum of odd numbers: " + sumOdd);
        System.out.println("Grand total: " + grandTotal);
    }
}
