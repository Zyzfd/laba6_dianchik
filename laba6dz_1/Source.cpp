#include <stdio.h>
#include <locale.h>
#include <math.h>

const double PI = 3.14159265358979323846264338327950288419716939937510;

float fun(float x) {
    return x - 0.333f * cos(x) - 0.7f * PI;
}

float (*ssfun)(float) = &fun;

float Horda(float (*ssfun)(float), float eps) {
    float x1 = 0;
    float x2 = 3;
    float y2 = fun(x2);

    while (true) {
        float y1 = fun(x1);
        if ((y1 < eps && y1 > 0) || (y1 > -eps && y1 < 0)) {
            return x1;
        }
        x1 = x2 - y2 * ((x2 - x1) / (y2 - y1));
    }
}

int main() {

    setlocale(LC_ALL, "Rus");

    float eps = 0.001;

    printf("Корень уравнения с точностью %f равен %f \n", eps, Horda(fun, eps));

    return 0;
}