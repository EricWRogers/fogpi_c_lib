#include "fogpi.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int get_int()
{
    int x;
    int result;

    result = scanf("%d", &x);

    if (result == EOF) {
        exit(1);
    }
    else if (result == 0) {
        printf("Invalid input. Please enter an integer: ");
        clear_input_buffer();
        x = get_int();  // Try again recursively
    }
    else{
        clear_input_buffer();
    }

    return x;
}

char get_char()
{
    char c;

    int result = scanf("%c", &c);

    if (result == EOF)
    {
        exit(1);
    }
    else if (result == 0)
    {
        printf("Invalid input. Please enter an char: ");
        clear_input_buffer();
        c = get_char();
    }
    else {
        clear_input_buffer();
    }

    return c;
}

char* get_my_string() {
    char buffer[1024]; // Adjust the buffer size as needed
    char* input = NULL;
    int length;
    
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        length = strlen(buffer);
        
        // Remove the newline character if present
        if (length > 0 && buffer[length - 1] == '\n') {
            printf("%s\n", "replace");
            buffer[length - 1] = '\0';
        }

        // Allocate memory for the input string and copy the buffer
        input = (char*)malloc(length);
        if (input != NULL) {
            strcpy(input, buffer);
        }

        return input;
    }

    return input;
}

float get_float() {
    float x;
    int result;

    result = scanf("%f", &x);

    if (result == EOF) {
        exit(1);
    }
    if (result == 0) {
        printf("Invalid input. Please enter a float: ");
        clear_input_buffer();
        x = get_float(); // Try again recursively
    } else {
        clear_input_buffer();
    }

    return x;
}