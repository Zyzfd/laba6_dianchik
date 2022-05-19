#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int cifra(int number) {

    int cifra = 0;

    if (number < 0) number = -number;
    if (number < 0) return 2;

    while (number > 0) {
        cifra = cifra + (number % 10);
        number = number / 10;
    }

    if (cifra > 9)
        cifra = cifra / 10 + cifra % 10;
    if (cifra > 9)
        cifra = 1;

    return cifra;
}

int main()
{
    setlocale(LC_ALL, "Rus");

    int a;

    while (1) {

        printf("Введите число \n");
        if (scanf_s("%d", &a) < 1) {
            printf("Учитель Йода говорит: 'Только целый числа нужны нам. Ошибку допустил ты...'\n");
            return 0;
        }
        printf("Вы ввели: %i\n", a);
        printf("Сумма чисел числа равна: %i\n", cifra(a));

    }

    return 0;
}