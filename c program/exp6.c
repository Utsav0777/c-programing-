#include<stdio.h>


void counterFuc(){

    static int count=1;
    printf("The function is called %d times.\n",count);
    count++;
}


int main(){

    counterFuc();
    counterFuc();
    counterFuc();

return 0;
}