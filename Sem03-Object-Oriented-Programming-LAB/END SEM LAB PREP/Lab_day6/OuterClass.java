class OuterClass {
    int x = 10;

    class InnerClass {
        int y = 5;

        void print() {
            System.out.println("x + y = " + (x + y));
        }
    }
    public static void main(String[] args) {
        OuterClass outer = new OuterClass();
        OuterClass.InnerClass inner = outer.new InnerClass();

        inner.print();
    }
}