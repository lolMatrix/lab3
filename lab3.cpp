#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <iostream>
#include "testing.h"
using namespace std;
const int REPEAT = 1001;

int main() {

	int a[20];
	int n;

	input_printf("Введите длинну массива: ");
	scanf("%d", &n);

	if (n < 2 || n > 20) {
		error_printf("Выход за диапозон");
		return 0;
	}

	input_printf("Введите массив:\n");
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i] < -1000 || a[i] > 1000) {
			error_printf("Выход за диапозон");
			return 0;
		}
	}

	int k = 0;

	for (int i = 0; i < n; i++) {
		bool isFirst = false;
		if(a[i] != REPEAT){
			for (int j = i + 1; j < n; j++) {
				if (a[i] == a[j]) {
					if (!isFirst) {
						input_printf("%d) Совпадают: ", k + 1);
						printf("%d", i);
						isFirst = !isFirst;
						k++;
					}
					printf(" %d", j);
					a[j] = REPEAT;
					if (j == n - 1)
						printf("\n");
				}
			}
			
		}
	}

	if (k == 0)
		printf("no solution");

}