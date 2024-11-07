/*
 * Program on type promotion and type casting
 */

public class main8 {
    public static void main(String[] args) {
        // Type Promotion
        byte byteValue = 10;
        int intValue = byteValue; // byte is promoted to int
        System.out.println("Type Promotion - byte to int: " + intValue);

        char charValue = 'A';
        int intValue2 = charValue; // char is promoted to int
        System.out.println("Type Promotion - char to int: " + intValue2);

        // Type Casting
        double doubleValue = 123.45;
        int intValue3 = (int) doubleValue; // double is casted to int
        System.out.println("Type Casting - double to int: " + intValue3);

        float floatValue = 45.67f;
        int intValue4 = (int) floatValue; // float is casted to int
        System.out.println("Type Casting - float to int: " + intValue4);

        // Type Casting with Loss of Precision
        int intValue5 = 200;
        byte byteValue2 = (byte) intValue5; // int is casted to byte (with potential loss of data)
        System.out.println("Type Casting with Loss of Precision - int to byte: " + byteValue2);

        int intValue6 = 300;
        byte byteValue3 = (byte) intValue6; // int is casted to byte (with wrap-around)
        System.out.println("Type Casting with Wrap-Around - int to byte: " + byteValue3);
    }
}
