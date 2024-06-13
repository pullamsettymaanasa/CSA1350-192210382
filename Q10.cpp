#include <stdio.h>
#include <stdbool.h>

// Define maximum number of states and symbols
#define MAX_STATES 10
#define MAX_SYMBOLS 10

// Structure to represent transitions
typedef struct {
    bool transitions[MAX_STATES][MAX_SYMBOLS];
    bool epsilonTransitions[MAX_STATES];
} NFA;

// Function to find e-closure for a given state
void findEpsilonClosure(NFA *nfa, int state, bool *visited) {
    visited[state] = true;

    for (int nextState = 0; nextState < MAX_STATES; nextState++) {
        if (nfa->epsilonTransitions[state] && !visited[nextState] && nfa->epsilonTransitions[nextState]) {
            findEpsilonClosure(nfa, nextState, visited);
        }
    }
}

// Function to print e-closure for all states
void printEpsilonClosure(NFA *nfa, int numStates) {
    for (int state = 0; state < numStates; state++) {
        bool visited[MAX_STATES] = {false};
        printf("e-closure(%d): { %d", state, state);

        findEpsilonClosure(nfa, state, visited);

        for (int nextState = 0; nextState < numStates; nextState++) {
            if (visited[nextState]) {
                printf(", %d", nextState);
            }
        }

        printf(" }\n");
    }
}

int main() {
    NFA nfa;
    int numStates, numSymbols;
    char symbols[MAX_SYMBOLS];

    printf("Number of states: ");
    scanf("%d", &numStates);

    printf("Number of symbols (excluding e): ");
    scanf("%d", &numSymbols);

    printf("Enter symbols: ");
    for (int i = 0; i < numSymbols; i++) {
        scanf(" %c", &symbols[i]);
    }

    // Initialize transitions and e-transitions
    for (int state = 0; state < numStates; state++) {
        for (int symbol = 0; symbol < numSymbols; symbol++) {
            nfa.transitions[state][symbol] = false;
        }
        nfa.epsilonTransitions[state] = false;
    }

    // Input transitions
    for (int state = 0; state < numStates; state++) {
        printf("State %d:\n", state);
        for (int symbol = 0; symbol < numSymbols; symbol++) {
            char input;
            printf("  - On input %c: ", symbols[symbol]);
            scanf(" %c", &input);
            if (input != 'e') {
                nfa.transitions[state][symbol] = true;
            } else {
                nfa.epsilonTransitions[state] = true;
            }
        }
    }

    // Print e-closure for all states
    printEpsilonClosure(&nfa, numStates);

    return 0;
}

