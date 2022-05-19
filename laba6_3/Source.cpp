#include <stdio.h>
#include <locale.h>
#include <math.h>

const double PI = 3.14159265358979323846264338327950288419716939937510;

float fun(float x) {
    return x - 0.333f * cos(x) - 0.7f * PI;
}

float (*ssfun)(float) = &fun;

int sign(float x) {
    if (x > 0.0) {
        return 1;
    }
    else if (x < 0.0) {
        return -1;
    }
    else {
        return 0;
    }
}

float Bisection(float (*ssfun)(float), float eps) {
    float x1 = 0;
    float x2 = 3;

    while (true) {
        float y1 = fun(x1);
        float y2 = fun(x2);
        if ((y1 < eps && y1 > 0) || (y1 > -eps && y1 < 0)) {
            return x1;
        }
        if ((y2 < eps && y2 > 0) || (y2 > -eps && y2 < 0)) {
            return x2;
        }
        float x3 = (x1 + x2) / 2.0;
        float y3 = fun(x3);
        if (sign(y3) == sign(y1)) {
            x1 = x3;
        } else {
            x2 = x3;
        }
    }
}

int main() {

    setlocale(LC_ALL, "Rus");

    float eps = 0.001;


    printf("Корень уравнения с точностью %f равен %f \n", eps, Bisection(fun, eps));

    return 0;
}