#include <stdio.h>
#include <stdbool.h>

bool validate_string(char *str) {
  // Check base cases (empty string for A and complete string for S)
  if (*str == '\0' && *(str + 4) == '\0' && *(str + 5) == '\0') {
    return str[1] == '1' && str[2] == '0' && str[3] == '1';  // Check for A101A
  }

  // Check production A -> 0A
  if (*str == '0') {
    return validate_string(str + 1);
  }

  // Check production A -> 1A
  if (*str == '1') {
    return validate_string(str + 1);
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

