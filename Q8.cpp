#include <stdio.h>
#include <string.h>

// Function to check if the input string matches the pattern
int checkPattern(char str[]) {
    int len = strlen(str);
    
    // Check if the string is empty
    if (len == 0) {
        return 0; // Not matching
    }
    
    // Check if the string starts with 'b' and ends with 'a'
    if (str[0] == 'b' && str[len - 1] == 'a') {
        return 1; // Matching
    } else {
        return 0; // Not matching
    }
}

int main() {
    char input[100];

    printf("Enter a string to check if it starts with 'b' and ends with 'a': ");
    scanf("%s", input);

    if (checkPattern(input)) {
        printf("The string matches the pattern.\n");
    } else {
        printf("The string does not match the pattern.\n");
    }

    return 0;
}

