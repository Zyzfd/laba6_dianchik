#include <stdio.h>
#include <locale.h>

void comparison() {

    float x4 = 0.1;
    double x8 = 0.1;

    if (x4 == x8)
        printf("x4 == x8\n");
    else
        printf("x4 != x8\n");

}

void summation_sequence() {

    int j;
    float summ = 0;
    for (j = 1; j <= 1000; j++)
        summ += 1.0 / j;
    printf("Сумма равна %12.9f\n", summ);
    summ = 0;
    for (j = 1000; j >= 1; j--)
        summ += 1.0 / j;
    printf("Сумма равна %12.9f\n", summ);

}

int main() {

    setlocale(LC_ALL, "Rus");

    comparison();
    summation_sequence();

    return 0;
}