#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a node in the adjacency list
typedef struct Node {
    int state;
    struct Node* next;
} Node;

// Structure to represent the NFA
typedef struct {
    int numStates;
    Node** transitions;
    bool* epsilonClosure;
} NFA;

// Function to create a new node for the adjacency list
Node* createNode(int state) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->state = state;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the adjacency list
void addEdge(NFA* nfa, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = nfa->transitions[src];
    nfa->transitions[src] = newNode;
}

// Function to perform DFS to find e-closure for a state
void findEpsilonClosure(NFA* nfa, int state, bool* visited) {
    visited[state] = true;
    nfa->epsilonClosure[state] = true;

    Node* current = nfa->transitions[state];
    while (current != NULL) {
        int nextState = current->state;
        if (!visited[nextState]) {
            findEpsilonClosure(nfa, nextState, visited);
        }
        current = current->next;
    }
}

// Function to print e-closure for all states
void printEpsilonClosure(NFA* nfa) {
    for (int state = 0; state < nfa->numStates; state++) {
        bool visited[nfa->numStates];
        for (int i = 0; i < nfa->numStates; i++) {
            visited[i] = false;
        }
        printf("e-closure(%d): { %d", state, state);
        findEpsilonClosure(nfa, state, visited);
        for (int i = 0; i < nfa->numStates; i++) {
            if (nfa->epsilonClosure[i]) {
                printf(", %d", i);
            }
        }
        printf(" }\n");
        for (int i = 0; i < nfa->numStates; i++) {
            nfa->epsilonClosure[i] = false; // Reset epsilon closure array
        }
    }
}

int main() {
    NFA nfa;
    int numStates, numTransitions;
    printf("Enter the number of states: ");
    scanf("%d", &numStates);
    nfa.numStates = numStates;

    // Allocate memory for transitions and epsilon closure
    nfa.transitions = (Node**)malloc(numStates * sizeof(Node*));
    nfa.epsilonClosure = (bool*)malloc(numStates * sizeof(bool));

    // Initialize adjacency lists and epsilon closure array
    for (int i = 0; i < numStates; i++) {
        nfa.transitions[i] = NULL;
        nfa.epsilonClosure[i] = false;
    }

    printf("Enter the number of transitions: ");
    scanf("%d", &numTransitions);

    printf("Enter the transitions (src dest symbol), use -1 for epsilon transition:\n");
    for (int i = 0; i < numTransitions; i++) {
        int src, dest;
        char symbol;
        scanf("%d %d %c", &src, &dest, &symbol);
        if (src == -1 || dest == -1) {
            printf("Invalid input: -1 is not allowed for src or dest.\n");
            return 1;
        }
        if (symbol == 'e') {
            addEdge(&nfa, src, dest);
        } else {
            printf("Invalid input: Only epsilon transitions (e) are supported.\n");
            return 1;
        }
    }

    printf("\nEpsilon closures:\n");
    printEpsilonClosure(&nfa);

    // Free allocated memory
    for (int i = 0; i < numStates; i++) {
        Node* current = nfa.transitions[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(nfa.transitions);
    free(nfa.epsilonClosure);

    return 0;
}

