abstract class Student {
    int rollNo;
    int regNo;

    abstract void course();
}

class Kiitian extends Student {
    @Override
    void course() {
        System.out.println("B.Tech Computer Science");
    }
}

public class main5 {
    public static void main(String[] args) {
        Kiitian kiitian = new Kiitian();
        kiitian.rollNo = 123456;
        kiitian.regNo = 789012;

        System.out.println("Roll no: " + kiitian.rollNo);
        System.out.println("Reg no: " + kiitian.regNo);

        kiitian.course();
    }
}
