#include <stdio.h>
#include <errno.h>
#include <ctype.h>
#include <stdlib.h>

unsigned short calibration_value (char str []);

int main () {

    FILE *input = NULL;

    input = fopen ("./input", "r");

    if (input == NULL) {
        perror ("Wasn't able to open the input file");
        return -1;
    }

    const size_t max_line_size = 100;
    char line [max_line_size] = {};
    unsigned int result = 0;

    while (fgets (line, max_line_size, input)) {

        result += calibration_value (line);

    }

    printf ("The sum of all the calibration values is: %u\n", result);

    return 0;

}

unsigned short calibration_value (char str []) {

    char first_digit = '\0'; 
    char last_digit = '\0'; 
    size_t i = 0;

    while (str [i] != '\0') {
        if (isdigit (str [i])) {
            if (first_digit == '\0') {
                first_digit = last_digit = str [i];
            } else {
                last_digit = str [i];
            }
        }
        ++i;
    }

    char value [] = {first_digit, last_digit};


    return strtoul (value, NULL, 10);

}
