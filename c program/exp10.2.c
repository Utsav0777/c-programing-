#include <stdio.h>

int main() {
    int arr[5], *ptr;
    
    printf("Enter 5 elements:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }

    ptr = arr + 4; 

    printf("Array in reverse order:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *ptr);
        ptr--; 
    }

    printf("\n");

    return 0;
}
