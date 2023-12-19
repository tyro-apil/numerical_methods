#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double func1(double x);
double func2(double x);
double func3(double x);
void solution();

int main(){
    solution();
    return 0;
}

void solution(){
    double (*func)(double) = func3;
    double x0, x1, x2, tolerance=0.00005;
    int counter=0;
    printf("Enter two initial approximations: ");
    scanf("%lf %lf", &x0, &x1);
    do{
        counter++;
        if (fabs(func(x1)-func(x0)) <= tolerance){
            printf("Secant line became horizontal\n");
            exit(0);
        }
        x2 = (func(x1)*x0 - func(x0)*x1)/(func(x1)-func(x0));
        x0 = x1;
        x1 = x2;
        if (counter >= 50){
            printf("Function doesnot have root\n");
            exit(0);
        }
    }while(fabs(func(x2)) >= tolerance);
    printf("Root=%lf Value=%lf\n", x2, func(x2));
}

double func1(double x){
    return (x*x- exp(-x));
}

double func2(double x){
    return (x*x + 1);
}

double func3(double x){
    return (x*x);
}
