public class main5 {

    public static void main(String[] args) {
        if (args.length < 10) {
            System.out.println("Please provide 10 integers as command-line arguments.");
            return;
        }

        // Display every alternate integer
        for (int i = 0; i < args.length; i += 2) {
            int num = Integer.parseInt(args[i]);
            System.out.println("Alternate Integer " + (i / 2 + 1) + ": " + num);
        }
    }
}
