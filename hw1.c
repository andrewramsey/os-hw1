#include <stdio.h>
#include <stdlib.h>

// The multiply function that multiplies the indices of arrays with each other
int multiply(int a, int b) {
    return a * b;
}

int main() {
    printf("Start program \n");
    int size;  
    FILE *fptr;

    // Ask the user for the size of the arrays
    printf("Input array size: ");
    scanf("%d", &size); // Takes user input to use for size, %d takes the int and &size puts the int into address of size

    // Creates arrays of ints using pointers and dynamically allocated memory
    int *array1 = (int *)malloc(size * sizeof(int));
    int *array2 = (int *)malloc(size * sizeof(int));

    // Print address of the first array
    printf("Address array1 after allocation: %p\n", &array1);

    // Print size of array pointer in bytes, not the actual length of array
    printf("Size of array1 pointer: %zu \n", sizeof(array1)); // %zu is long unsigned int, using %d creates warnings

    int i; // initialize i for loops
    
    // Take user input for every element in both arrays
    printf("Input content of array1:\n");
    for (i = 0; i < size; i++) 
    {
        printf("array1[%d]: ", i); // Ask for input
        scanf("%d", &array1[i]);   // Scans into array index
    }
    printf("Input content for array2:\n");
    for (i = 0; i < size; i++) 
    {
        printf("array2[%d]: ", i);
        scanf("%d", &array2[i]);
    }

    // Open file to write results
    fptr = fopen("hw1_output.txt", "w");

    printf("Multiplication start \n");
    // Perform multiplication and write to file
    for (i = 0; i < size; i++) {
        int product = multiply(array1[i], array2[i]);
        if (product % 2 == 0) // If the remainder of product when divided by 2 is 0, its even
        {
            fprintf(fptr, "array1[%d] * array2[%d] = %d \n", i, i, product); // fprintf writes to file 
            fprintf(fptr, " %d is an even number\n", product);
        } 
        else 
        {
            fprintf(fptr, "array1[%d] * array2[%d] = %d \n", i, i, product);
            fprintf(fptr, " %d is an odd number\n", product);
        }
    }
    printf("Multiplication done\n");

    // Close file after writing
    fclose(fptr);

    printf("Read file\n");
    // Open file to read and print 
    fptr = fopen("hw1_output.txt", "r");

    // Print content of the file
    char ch;
    while ((ch = fgetc(fptr)) != EOF) // Gets the next character until end of file
    {
        putchar(ch);  // Writes each character 
    }

    // Close the file after reading
    fclose(fptr);

    // Free memory
    free(array1);
    free(array2);

    printf("End of program\n");
    return 0;
}
