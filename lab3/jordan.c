#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define rows    20
#define cols    20

void solution();

int main(){
    solution();
    return 0;
}

void solution(){
    int n;
    float mat[rows][cols], *x;
    printf("Enter number of unknowns: ");
    scanf("%d", &n);

    // Dynamic allocation
    x = (float*)malloc(n*sizeof(*x));

    // Take input elements
    for(int i=0; i<n; i++){
        for(int j=0; j<n+1; j++){
            printf("mat[%d][%d] = ", i+1, j+1);
            scanf("%f", &mat[i][j]);
        }
    }

    // Diagonlize the matrix
    for(int j=0; j<n; j++){
        if (fabs(mat[j][j]) <= 0.005){
            printf("%d\n", j);
            printf("Pivotal element is zero\n");
            exit(1);
        }
        for (int i=0; i<n; i++){
            if(i != j){
                float t = mat[i][j]/mat[j][j];
                for(int k=0; k<n+1; k++){
                    mat[i][k] = mat[i][k]-t*mat[j][k];
                }
            }
        }
    }

    //Find the unknowns
    for(int i=0; i<n; i++){
        *(x+i) = mat[i][n]/mat[i][i];
        printf("x[%d] = %10.4f\n", i+1, *(x+i));
    }
}
