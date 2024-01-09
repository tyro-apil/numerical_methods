#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define rows 		20
#define cols		20

void solution();

int main(){
	solution();
	return 0;
}

void solution(){
    int n;
	float mat[rows][cols], *x;
	printf("Enter order of matrix: ");
	scanf("%d", &n);

	x=(float*)malloc(n*sizeof(*x));

	// input
	for(int i=0; i<n; i++){
		for(int j=0; j<2*n; j++){
            if(j<n){
                printf("mat[%d][%d]= ", i+1, j+1);
                scanf("%f",&mat[i][j]);
            }
            else if (j==n+i){
                mat[i][j]=1;
            }
            else{
                mat[i][j]=0;
            }
		}
	}

    // diagonalize
    for(int j=0; j<n; j++){
        if (fabs(mat[j][j]) <= 0.005){
            printf("%d\n", j);
            printf("Pivotal element is zero\n");
            exit(1);
        }
        for (int i=0; i<n; i++){
            if(i != j){
                float t = mat[i][j]/mat[j][j];
                for(int k=0; k<2*n; k++){
                    mat[i][k] = mat[i][k]-t*mat[j][k];
                }
            }
        }
    }

    // convert to identity
    for(int i=0; i<n; i++){
        for(int j=0; j<2*n; j++){
            mat[i][j] = mat[i][j]/mat[i][i];
        }
    }

    // output
    for(int i=0; i<n; i++){
        for(int j=n; j<2*n; j++){
            printf("%f\t",mat[i][j]);
        }
        printf("\n");
    }
}