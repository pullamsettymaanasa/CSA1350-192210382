#include <stdio.h>

int main() {
  char ch;
  int state = 0;  // Initial state

  printf("Enter a string: ");
  while ((ch = getchar()) != '\n') {
    if (state == 0) {
      if (ch == 'a') {
        state = 1;
      } else {
        state = -1;  // Invalid state
        break;
      }
    } else if (state == 1) {
      if (ch != 'a') {
        state = 1;  // Stay in state 1 for any character other than 'a'
      }
    } else {
      break;  // Exit loop if invalid state is reached
    }
  }

  if (state == 1) {
    printf("String accepted (starts and ends with 'a').\n");
  } else {
    printf("String rejected.\n");
  }

  return 0;
}

