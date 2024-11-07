/*
2.1 Aim of the program: Write a program in C to convert the first „n‟ decimal numbers of a disc
file to binary using recursion. Store the binary value in a separate disc file.
Note# Read the value of „n‟, source file name and destination file name from command line
arguments. Display the decimal numbers and their equivalent binary numbers from the output
file.
Give the contents of the input disc file “inDec.dat” as
30 75 2564 ...
Contents of the output disc file “outBin.dat” as
The binary equivalent of 30 is 0000000000011110
The binary equivalent of 75 is 0000000001001011
The binary equivalent of 2564 is 0000101000000100
Terminal Input:
$gcc lab2q1.c -o lab2q1
$./lab2q1 150 inDec.dat outBin.dat
Output: Content of the first „n‟ decimal and their equivalent binary numbers
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decToBinary(int n, FILE *fp) {
    if (n == 0)
        return;
    decToBinary(n / 2, fp);
    fprintf(fp, "%d", n % 2);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <n> <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[2], "r");
    if (input == NULL) {
        printf("Error: Unable to open the input file\n");
        return 1;
    }

    FILE *output = fopen(argv[3], "w");
    if (output == NULL) {
        printf("Error: Unable to open the output file\n");
        return 1;
    }

    int n = atoi(argv[1]);
    int num;
    for (int i = 0; i < n; i++) {
        fscanf(input, "%d", &num);
        fprintf(output, "The binary equivalent of %d is ", num);
        decToBinary(num, output);
        fprintf(output, "\n");
    }

    fclose(input);
    fclose(output);

    return 0;
}