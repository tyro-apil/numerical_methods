#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double func(double x);
void solution();

int main(){
	solution();
	return 0;
}

void solution(){
	double a, b, c, tolerance, temp;
	printf("Enter the interval [a,b]: ");
	scanf("%lf %lf", &a, &b);
	printf("Enter the tolerance value: ");
	scanf("%lf", &tolerance);
	if (func(a)*func(b) > 0){
		printf("Root doesnot lie in given interval\n");
		exit(0);
	}
	do{
		c = a - (func(a)*((b-a)/(func(b)-func(a))));
		a = b;
		b = c;
	}while(fabs(func(c)) >= tolerance);
	printf("Root = %lf Function = %lf\n", c, func(c));
}

double func(double x){
	return (3*sin(x)-6*log10(x));
}
