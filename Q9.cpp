#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Define the number of states in the NFA
#define NUM_STATES 3

// Define the symbols in the alphabet
#define SYMBOLS 2

// Define the transition table for the NFA
int transitionTable[NUM_STATES][SYMBOLS][NUM_STATES] = {
    {{0, 1}, {-1, -1}},  // State 0
    {{-1, -1}, {2, -1}}, // State 1
    {{-1, -1}, {-1, -1}} // State 2 (final state)
};

// Function to check if the input string is accepted by the NFA
bool isAccepted(char *input) {
    int currentState = 0;
    int inputLength = strlen(input);

    for (int i = 0; i < inputLength; i++) {
        char symbol = input[i];
        int symbolIndex;

        if (symbol == 'o') {
            symbolIndex = 0;
        } else if (symbol == '1') {
            symbolIndex = 1;
        } else {
            // Invalid symbol, reject the input
            return false;
        }

        int nextState = transitionTable[currentState][symbolIndex][0];

        if (nextState == -1) {
            // Transition not defined for the current symbol, reject the input
            return false;
        }

        currentState = nextState;
    }

    // Check if the final state is reached
    return currentState == 2;
}

int main() {
    char input[100];

    printf("Enter a string: ");
    scanf("%s", input);

    if (isAccepted(input)) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }

    return 0;
}

