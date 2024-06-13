#include <stdio.h>
#include <stdbool.h>

bool validate_string(char *str) {
  if (*str == '\0') {
    return true;  // Empty string (e) is valid for A
  }

  // Check for production S -> A
  if (*str == 'A') {
    return true;
  }

  // Check if string starts with '0' for production S -> 0S0
  if (*str == '0' && str[1] == 'S') {
    return validate_string(str + 2);  // Recursively check the remaining string
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

