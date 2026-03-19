#include <stdio.h>
#include <string.h>

int palindrome(char s[]) {
    char rev[100];
    int len = strlen(s);
    
    for (int i = 0; i < len; i++) {
        rev[i] = s[len - i - 1];
    }
    rev[len] = '\0';

    return strcmp(s, rev) == 0;
}

int main() {
    char s[100];

    printf("Enter a string: ");
    scanf("%s", s);

    if (palindrome(s)) {
        printf("The entered string is a palindrome.\n");
    } else {
        printf("The entered string is not a palindrome.\n");
    }

    return 0;
}
