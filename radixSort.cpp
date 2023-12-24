#include "int.h"

void radixSort(int* arr, int n);
int getMaxAbs(int* arr, int n);
void countSort(int* arr, int n, int r);
void merge(int* arr1, int* arr2, int* arrMerge, int len1, int n);

void radixSort(int* arr, int n) {
	int count_p = 0, count_m = 0, r = getMaxAbs(arr, n);
	for (int i = 0; i < n; i++) {
		if (arr[i] >= 0.0) count_p++;
		else count_m++;
	}
	int* plus = (int*)malloc(count_p * sizeof(int));
	int* minus = (int*)malloc(count_m * sizeof(int));
	int i = 0, j = 0, k = 0;
	while (k < n) {
		if (arr[k] >= 0.0) plus[i++] = arr[k++];
		else minus[j++] = arr[k++];
	}
	for (int i = 0; i < r; i++) {
		countSort(plus, count_p, i);
		countSort(minus, count_m, i);
	}
	merge(minus, plus, arr, count_m, n);
}

void countSort(int* arr, int n, int r) {
	int* arr_new = (int*)malloc(n * sizeof(int));
	int* count = (int*)malloc(sizeof(int) * 10);

	for (int i = 0; i < 10; i++) count[i] = 0;

	for (int i = 0; i < n; i++) {
		int p = ((int)(abs(arr[i]) / (pow(10, r)))) % 10;
		count[p]++;
	}
	for (int i = 1; i < 10; i++) count[i] += count[i - 1];
	for (int i = n - 1; i >= 0; i--) {
		int p = ((int)(abs(arr[i]) / (pow(10, r)))) % 10;
		arr_new[--count[p]] = arr[i];
	}
	copyI(arr, arr_new, n);
	free(arr_new);
	free(count);
}

int getMaxAbs(int* arr, int n) {
	int max = -1000000000;
	for (int i = 0; i < n; i++) if (abs(arr[i]) > max) max = arr[i];
	int r = 0;
	while (max > 0) {
		r++;
		max = max / 10;
	}
	return r;
}

void merge(int* arr1, int* arr2, int* arrMerge, int len1, int n) {
	int j = 0;
	for (int i = len1 - 1; i >= 0; i--) arrMerge[j++] = arr1[i];
	for (int i = 0; i < n - len1; i++) arrMerge[j++] = arr2[i];
}