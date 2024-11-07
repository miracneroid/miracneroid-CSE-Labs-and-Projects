/*
2.2 Aim of the program: Write a program in C to find GCD of two numbers using recursion.
Read all pair of numbers from a file and store the result in a separate file.
Note# Source file name and destination file name taken from command line arguments. The
source file must contain at least 20 pairs of numbers.
Give the contents of the input disc file “inGcd.dat” as 8 12 20 45 30 80
Contents of the output disc file “outGcd.dat” as
The GCD of 8 and 12 is 4
The GCD of 20 and 45 is 5
The GCD of 30 and 80 is 10
Terminal Input:
$gcc lab2q2.c -o lab2q2
$./lab2q2 inGcd.dat outGcd.dat
Output: Display the gcd stored in the output file outGcd.dat
*/

#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (input == NULL) {
        printf("Error: Unable to open the input file\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL) {
        printf("Error: Unable to open the output file\n");
        return 1;
    }

    int a, b;
    while (fscanf(input, "%d %d", &a, &b) != EOF) {
        fprintf(output, "The GCD of %d and %d is %d\n", a, b, gcd(a, b));
    }

    fclose(input);
    fclose(output);
    return 0;
}
