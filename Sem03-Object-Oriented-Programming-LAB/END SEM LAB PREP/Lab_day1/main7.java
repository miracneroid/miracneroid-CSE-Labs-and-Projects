public class main7 {
    public static void main(String[] args) {
        if (args.length != 3) {
            System.out.println("Please provide marks for all three subjects.");
            return;
        }
        
        try {
            double subject1 = Double.parseDouble(args[0]);
            double subject2 = Double.parseDouble(args[1]);
            double subject3 = Double.parseDouble(args[2]);
            
            double average = (subject1 + subject2 + subject3) / 3.0;

            String grade;

            if (average >= 90) {
                grade = "A+";
            } else if (average >= 80) {
                grade = "A";
            } else if (average >= 70) {
                grade = "B";
            } else if (average >= 60) {
                grade = "C";
            } else if (average >= 50) {
                grade = "D";
            } else {
                grade = "F";
            }

            System.out.println("Average Mark: " + average);
            System.out.println("Grade: " + grade);

        } catch (NumberFormatException e) {
            System.out.println("Invalid input. Please provide valid numerical marks.");
        }
    }
}
