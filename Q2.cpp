#include <stdio.h>

int main() {
  char ch;
  int state = 0;  // Initial state

  printf("Enter a string (must start with 0 and end with 1): ");
  while ((ch = getchar()) != '\n') {
    if (state == 0) {
      if (ch == '0') {
        state = 1;
      } else {
        state = -1;  // Invalid state
        break;
      }
    } else if (state == 1) {
      if (ch != '1') {
        state = 1;  // Stay in state 1 for any character other than '1'
      }
    } else {
      break;  // Exit loop if invalid state is reached
    }
  }

  if (state == 1) {
    printf("String accepted (starts with 0 and ends with 1).\n");
  } else {
    printf("String rejected.\n");
  }

  return 0;
}

