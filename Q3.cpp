#include <stdio.h>
#include <stdbool.h>

bool validate_string(char *str) {
  int state = 0;  // Initial state

  while (*str != '\0') {
    switch (state) {
      case 0:
        if (*str == '0') {
          state = 1;
        } else {
          return false;
        }
        break;
      case 1:
        if (*str == '0' || *str == '1') {
          state = 1;
        } else if (*str == 'A') {
          state = 2;
        } else {
          return false;
        }
        break;
      case 2:
        if (*str == '1') {
          state = 3;
        } else {
          return false;
        }
        break;
      case 3:
        return true;  // Reached final state with successful parsing
    }
    str++;
  }

  // String ended without reaching final state
  return (state == 3);
}

int main() {
  char str[100];

  printf("Enter a string: ");
  scanf("%s", str);

  if (validate_string(str)) {
    printf("String belongs to the language.\n");
  } else {
    printf("String does not belong to the language.\n");
  }

  return 0;
}

