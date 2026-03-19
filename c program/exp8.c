#include <stdio.h>

int main() {
    char s[100];
    int len = 0;

    printf("Enter a string: ");
    scanf("%[^\n]",s);

    while (s[len] != '\0') {
        len++;
    }

    printf("The length of the string is: %d\n", length);
    return 0;
}
