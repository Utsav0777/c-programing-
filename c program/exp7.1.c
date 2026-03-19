int main(){

    int s;
    printf("Enter size of Square Matrix : ");
    scanf("%d",&s);

    int a1[s][s], a2[s][s], sum[s][s];

    printf("\nEnter Matrix A: \n");
    for(int i = 0; i < s; i++){

        for(int j = 0; j < s; j++){

            printf("Enter element a%d%d :", i + 1, j + 1);
            scanf("%d", &a1[i][j]);

        }
    }

    printf("\nEnter Matrix B: \n");
    for(int i = 0; i < s; i++){

        for(int j = 0; j < s; j++){

            printf("Enter element a%d%d :", i + 1, j + 1);
            scanf("%d", &a2[i][j]);

        }
    }

    for(int i = 0; i < s; i++){
        for(int j = 0; j < s; j++){
            
            sum[i][j] = a1[i][j] + a2[i][j];
            
        }
    }
    
    printf("\nSum Matrix of A and B is\n");
    for(int i = 0; i < s; i++){
        for(int j = 0; j < s; j++){
            printf("a%d%d : %d\n", i + 1, j + 1, sum[i][j]);        
            
        }
    }

    return 0;
}
