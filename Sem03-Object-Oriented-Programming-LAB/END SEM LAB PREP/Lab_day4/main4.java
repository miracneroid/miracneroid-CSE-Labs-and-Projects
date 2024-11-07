class MathOperations {
    
    public int add(int a, int b) {
        return a + b;
    }

    public float add(int a, float b) {
        return a + b;
    }

    public float add(float a, int b) {
        return a + b;
    }
}

public class main4 {
    public static void main(String[] args) {
        MathOperations math = new MathOperations();

        int result1 = math.add(5, 10);
        System.out.println("Result 1 (int + int): " + result1);

        float result2 = math.add(5, 10.5f);
        System.out.println("Result 2 (int + float): " + result2);

        float result3 = math.add(7.5f, 2);
        System.out.println("Result 3 (float + int): " + result3);
    }
}
