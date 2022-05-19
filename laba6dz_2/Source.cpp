#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <malloc.h>

const double PI = 3.14159265358979323846264338327950288419716939937510;

float fun(float x) {
	return x - 0.333f * cos(x) - 0.7f * PI;
}

float (*ssfun)(float) = &fun;

float Simpson(float (*ssfun)(float), float x1, float x2) {
	float h = (x2 - x1) / 2.0;
	float sum = fun(x1) + (4.0 * fun(x1 + h)) + fun(x2);
	return (h / 3.0) * sum;
}

int main() {
	setlocale(LC_ALL, "Rus");

	float x1 = 0;
	float x2 = 5;
	printf("Определенный интеграл от %f до %f равен %f \n", x1, x2, Simpson(fun, x1, x2));

	return 0;
}