#include <stdio.h>
#include <stdbool.h>
#include <cstring>  // Include for strlen

bool validate_string(char *str) {
  if (*str == '\0') {
    return true;  // Empty string (e) is valid
  }

  // Check for production S -> 0S1
  if (*str == '0') {
    int len = strlen(str);
    if (len > 1 && str[len - 1] == '1') {  // Ensure length > 1 and ends with 1
      return validate_string(str + 1);  // Recursively check the middle part
    }
  }

  // String doesn't follow any production rule
  return false;
}

int main() {
  char str[100];

  printf("Enter a string (must start with 0 and end with 1): ");
  scanf("%s", str);

  if (validate_string(str)) {
    printf("String belongs to the language.\n");
  } else {
    printf("String does not belong to the language.\n");
  }

  return 0;
}

