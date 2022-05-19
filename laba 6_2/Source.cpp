#include <stdio.h>
#include <locale.h>
#include <math.h>
#define count 27

int float_comparison_1(float a, float b, int N) {

    for (int i = 0; i < N; i++) {
        a *= 10;
        b *= 10;
        if ((int)a == (int)b) return 1;
        a -= (int)a;
        b -= (int)b;
    }
    return 0;
}

int float_comparison_N(float a, float b, int N) {

    for (int i = 0; i < N; i++) {
        a *= 10;
        b *= 10;
        if ((int)a != (int)b) return 0;
        a -= (int)a;
        b -= (int)b;
    }
    return 1;
}

float Bakers_map(float x) {

    if (x < 0.5)
        return 2.0 * x;
    else
        return 2.0 * x - 1.0;

}


int main() {

    setlocale(LC_ALL, "Rus");

    float number = 0.2;
    float temp = number;
    for (int i = 0; i < count; i++) {
        temp = Bakers_map(temp);
        printf("%f ", number);
        printf(" %f ", temp);
        printf(" Числа равны?: %d %d\n", float_comparison_N(number, temp, 5), float_comparison_1(number, temp, 5));
    }
    
    return 0;
}