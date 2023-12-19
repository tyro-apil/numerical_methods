#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double diff(double(*func)(double), double x);
double func1(double x);
double func2(double x);
double func3(double x);

void solution();

int main(){
	solution();
	return 0;
}

void solution(){
	double a, b, tolerance, temp, stationary_tolerance;
    int counter=0;
    tolerance = 0.0005;
    stationary_tolerance = 1e-6;
    printf("Enter approximate solution: ");
    scanf("%lf", &a);
	double (*func)(double) = func2;
    do{
        counter++;
        if (fabs(diff(func, a)) <= stationary_tolerance){
            printf("Given approximation is a stationary point\n");
            exit(0);
        }
        b = a - (func(a)/diff(func, a));
        a = b;
        if (counter >= 100){
            printf("Oscillating root problem\n");
            exit(0);
        }
    }while(fabs(func(b)) >= tolerance);
    printf("Root=%lf Func_val=%lf\n", b, func(b));
}

double diff(double(*func)(double), double x){
    double del_x = 1e-10;
    return (func(x+del_x)-func(x-del_x))/(2*del_x);
}

double func1(double x){
	return (3*sin(x)-6*log10(x));
}

double func2(double x){
    return (cos(x)+exp(-x)-5);
}

double func3(double x){
    return (log(x));
}

