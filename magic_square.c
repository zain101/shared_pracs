#include<stdio.h>


int main(){
    int a = 9;
    do{
        printf("\nEnter the size of matrix  ");
        scanf("%d", &a);
        if(a%2 == 0 || a == 1)
            printf("\nThe matrix size you entered is Even or <= 1, Please re-enter");
    }while(a%2 == 0 ||  a == 1);

    int i,j, mid;
    i=0, j=0;
    int **mat = (int **)malloc(a * sizeof(int *));
    for (i=0; i<a; i++)
        mat[i] = (int *)malloc(a * sizeof(int));
    printf("hello\n");
    for (i=0; i<a; i++){
        for(j=0;j<a;j++){
            printf(" %d ", mat[i][j]);
        }
        printf("\n");
    }
    int sum =0;
    mid = a/2;
    int *p = 0;
    int *q = mid;
    mat[0][mid] = 1;
//    printf("%d\n", mat[0][mid]);

    for(i=2; i<= a*a ; i++){
        //printf("hello \n");
        checkPosi(&p, &q, a, i, (int **)mat);
    }

    for (i=0; i<a; i++){
        sum = sum+mat[0][i];
    }
    printf("\nThe Magic constant is %d\n", sum);
    printf("\nThe magic square for %dx%d is\n", a,a );
    for (i=0; i<a; i++){
        for(j=0;j<a;j++){
            printf(" %d ", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void checkPosi(int *i, int *j, int a, int n, int **copy){
    printf("Send %d  %d \n ", *(i), *(j));
    int c_i = *(i);
    int c_j = *(j);
    *(i) = *(i)-1;
    *(j) = *(j)+1;
    if(*(i) < 0)
        *(i) = a-1;
    if(*(j) > a-1)
        *(j) = 0;
    printf("Alter %d  %d \n", *(i), *(j));
    if(copy[*(i)][*(j)] == 0){
        copy[*(i)][*(j)] = n;
        return;
    }
    else{
        *(i) = c_i;
        *(j) = c_j;
        printf("\nBefore %d \n", *(i));
        *(i) = *(i)+1;
        printf("\n %d \n", *(i));
        copy[*(i)][*(j)] = n;
    }

}
