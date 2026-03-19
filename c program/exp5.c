#include<stdio.h>

int calcFactIter(int n){
    int fact = 1;
    for(int i = 1; i <= n; i++){
        fact *= i;
    }
    return fact;
}

int calcFactRecur(int n){

    int fact = 1;

    if(n == 1){
        return fact;
    }

    fact = n * calcFactRecur(n-1);

    return fact;
}



int main(){


    int fact1 = calcFactIter(5);
    int fact2 = calcFactRecur(6);

    printf("Factorial using Iterative Function is %d", fact1);
    printf("\nFactorial using Recursive Function is %d", fact2);



return 0;
}