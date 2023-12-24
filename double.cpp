#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "basicSort.h"
#include "quickSort.h"
#include "mergeSort.h"

void visualization(); //визуализация выбора сортировки

void swapD(double* el1, double* el2); //обмен значениями перемнных типа double
void uniformD(double* arr, int n, int j); //заполнение массива равномернно распределёнными данными
void minTimeD(double* min_time, int n, pFD sort);//нахождение минимального времени для массива double из 3-х запусков

void copyD(double* arr, double* arr_new, int n); //копирование созданного массива
void verificationD(double* arr, double* arr_new, int n); //проверка на верную сортировку
void seeArrD(double* arr, int n); //визуализация массива

int cmp(const void* a, const void* b);
void minTimeD(double* min_time, int n, pFD sort) {
	for (int i = 0; i < 3; i++) {
		double* arr = (double*)malloc(n * sizeof(double));
		double* arr_new = (double*)malloc(n * sizeof(double)); //массив для проверки 
		double* bufMerge = (double*)malloc(n * sizeof(double)); //дполнительный массив для сортировки слиянием
		uniformD(arr, n, i); //заполнение обычного массива

		copyD(arr, arr_new, n);//заполнение массива для проверки 
		double time;
		clock_t start=0, stop=0;
		
		double * empty1=NULL;
		int empty2=0;

		if ((sort == bubbleSort) || (sort == insertSort) || (sort == selectionSort)) {
			start = clock();
			sort(arr, empty1,n, empty2);
			stop = clock();
		}
		if (sort == quickSort) {
			start = clock();
			sort(arr, empty1, 0, n - 1);
			stop = clock();
		}
		if (sort== mergeSort) {
			start = clock();
			sort(arr, bufMerge, 0, n);
			stop = clock();
		}
		verificationD(arr, arr_new, n); //проверка осортированности 
		time = ((double)(stop - start)) / CLOCKS_PER_SEC;
		printf("%lf\n", time);
		if (time < *min_time) *min_time = time;
		//seeArrD(arr, n); //просмотр отсортирвоанного массива

		free(arr);
		free(arr_new);
	}
}
void visualization() {
	char arr[][30] = { "BubbleSort","SelectionSort","InsertSort","QuickSort", "MergeSort", "RadixSort" };
	for (int i = 1; i < 7; i++) {
		printf("%d - %s\n", i, arr[i - 1]);
	}
}
int cmp(const void* a, const void* b) {
	return *(double*)a - *(double*)b;
}
void swapD(double* el1, double* el2) {
	double tmp = *el1;
	*el1 = *el2;
	*el2 = tmp;
}
void copyD(double* arr, double* arr_new, int n) {
	for (int i = 0; i < n; i++)arr_new[i] = arr[i];
}

void verificationD(double* arr, double* arr_new, int n) {
	qsort(arr_new, n, sizeof(double), cmp);
	//seeArr(arr_new, n);
	bool flag = true;
	for (int i = 0; i < n; i++) {
		if (arr_new[i] != arr[i]) {
			flag = false;
			printf("Errors ");
			break;
		}
	}
	if (flag) printf("Not errors ");
}

void seeArrD(double* arr, int n) {
	for (int i = 0; i < n; i++) printf("%lf ", arr[i]);
	printf("\n");
}

void uniformD(double* arr, int n, int j) {
	srand(time(NULL) + j);
	for (int i = 0; i < n; i++) {
		arr[i] = rand();
	}
}