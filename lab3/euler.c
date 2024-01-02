#include<stdio.h>
#include<math.h>

void solution();

float diff1(float, float);
float func1(float);

float diff2(float, float);
float func2(float);

float diff3(float, float);
float func3(float);

int main(){
    solution();
    return 0;
}

void solution(){
    float (*slope)(float, float) = diff1;
    float x0, y0, xn, m, x1, y1;
    float h;
    printf("Enter x0 y0 h xn: ");
    scanf("%f %f %f %f", &x0, &y0, &h, &xn);
    do{
        m = slope(x0, y0);
        y1 = y0+h*m;
        x1 = x0+h;
        x0 = x1;
        y0 = y1;
        printf("%10.4f %10.4f\n", x0, y0);
    }while(x0 < xn);
}

float diff1(float x,float y){
    return x+y;
}
