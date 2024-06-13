#include <stdio.h>
#include <stdbool.h>
#include <cstring>  // Include for strlen

bool validate_string(char *str) {
  if (*str == '\0') {
    return true;  // Empty string (e) is valid
  }

  // Check for base cases (0 or 1)
  if (*str == '0' || *str == '1') {
    return true;
  }

  int len = strlen(str);  // Get string length using strlen (safe with null-terminated strings)
  for (int i = 0; i < len - 1; i++) {
    // Check for productions S -> 0S0 or 1S1
    if (str[i] == '0' && str[i + 1] == 'S' && validate_string(str + i + 2)) {
      return true;
    } else if (str[i] == '1' && str[i + 1] == 'S' && validate_string(str + i + 2)) {
      return true;
    }
  }

  // String doesn't follow any production rule
  return false;
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

