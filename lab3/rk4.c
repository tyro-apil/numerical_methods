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
    float (*slope)(float, float) = diff3;
    float m, m1, m2, m3, m4, x0, y0, x1, y1, xn;
    float h;
    printf("Enter x0 y0 h xn: ");
    scanf("%f %f %f %f", &x0, &y0, &h, &xn);
    do{
        m1 = slope(x0, y0);
        m2 = slope(x0+((float)h/2), y0+m1*((float)h/2));
        m3 = slope(x0+((float)h/2), y0+m2*((float)h/2));
        m4 = slope(x0+h, y0+m3*h);
        m = (m1+2*m2+2*m3+m4)/6;
        y1 = y0+h*m;
        x1 = x0+h;
        x0 = x1;
        y0 = y1;
        printf("%10.4f %10.4f\n", x0, y0);
    }while(x0 < xn);
}

float diff1(float x, float y){
    return x+y;
}

float diff2(float x, float y){
    return x*cos(x);
}

float diff3(float x, float y){
    return x*x+y;
}
