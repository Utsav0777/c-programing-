#include<stdio.h>

int main(){

    int size, largest=0;

    printf("Enter size of array: ");
    scanf("%d",&size);

    int arr[size];

    for(int i=0; i < size; i++){
        printf("Enter element %d :",i+1);
        scanf("%d", &arr[i]);
    }

    for(int j=0; j < size; j++){
        if(largest<arr[j]){
            largest = arr[j];
        }
    }

    printf("The largest of the array is %d",largest);

return 0;
}