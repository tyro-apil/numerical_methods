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
	printf("Enter no. of unknowns: ");
	scanf("%d", &n);

	x=(float*)malloc(n*sizeof(*x));

	// input
	for(int i=0; i<n; i++){
		for(int j=0; j<n+1; j++){
			printf("mat[%d][%d]= ", i+1, j+1);
			scanf("%f",&mat[i][j]);
		}
	}

	// upper triangle
	for(int j=0; j<n; j++){
		if(fabs(mat[j][j]) <= 0.005){
			printf("Pivot element is zero\n");
			exit(1);
		}
		for (int i=j+1; i<n; i++){
            if(i != j){
                float t = mat[i][j]/mat[j][j];
                for(int k=0; k<n+1; k++){
					mat[i][k] = mat[i][k]-t*mat[j][k];
                }
            }
        }
		
		// for(int i=0; i<n; i++){
		// 	for(int j=0; j<n+1; j++){
		// 		printf("%f\t", mat[i][j]);
		// 	}
		// 	printf("\n");
		// }
		// getchar();
	}

	// back subs
	*(x+n-1) = mat[n-1][n]/mat[n-1][n-1];
	for(int i=n-2; i>=0; i--){
		float sum=0;
		for(int j=i; j<n; j++){
			sum+=mat[i][j]*x[j];
		}
		x[i]=(mat[i][n]-sum)/mat[i][i];
	}

	for(int i=0; i<n; i++){
		printf("x[%d]= %f\n", i+1, x[i]);
	}
}
