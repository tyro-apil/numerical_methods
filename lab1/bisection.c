/*
Implementation of bisection method to find root of non-linear functions
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int calc_iteration_count(float a, float b, float err);
float func(float x);
void solution();

int main(){
    solution();
    return 0;
}

void solution(){
    float lower_limit, upper_limit, midpoint, error;
    int iter_count = 0, total_iter_count;
    error = 0.0005;

    printf("Enter the limits of interval: ");
    scanf("%f %f", &lower_limit, &upper_limit);

    total_iter_count = calc_iteration_count(lower_limit, upper_limit, error);

    if (func(lower_limit)*func(upper_limit) < 0){
        do{
            midpoint = (upper_limit + lower_limit)/2;
            if (func(lower_limit)*func(midpoint) > 0){
                lower_limit = midpoint;
            }
            else{
                upper_limit = midpoint;
            }
            iter_count++;
            if (iter_count > total_iter_count){
                printf("Function is discontinuous");
                exit(0);
            }
        }while(fabs(func(midpoint)) > error);       // Donot use abs() because it will return absolute integer
        printf("Root = %.4f and y = %.4f\n", midpoint, func(midpoint));
    }
    else{
        printf("Root doesnot lie between %.4f and %.4f\n", lower_limit, upper_limit);
    }
}

float func(float x){
    return (x*sin(x)-1);
}

int calc_iteration_count(float a, float b, float err){
    return (int)log2((b-a)/err);
    
}