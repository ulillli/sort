#include "double.h"

void quickSort(double* arr, double * empty1, int left, int right);
int partition(double* arr, int left, int right);

void quickSort(double* arr, double * empty1, int left, int right) {
	if (right - left < 1) return;
	int q = partition(arr, left, right);
	if (q - left < right - q) {
		quickSort(arr, empty1, left, q - 1);
		quickSort(arr, empty1, q + 1, right);
	}
	else {
		quickSort(arr, empty1, q + 1, right);
		quickSort(arr, empty1, left, q - 1);
	}
}
int partition(double* arr, int left, int right) {
	double pivot = arr[right];
	int i = left - 1, j = right;
	while (true) {
		while (arr[++i] <= pivot) if (i >= j) break;
		while (arr[--j] > pivot) if (j == left) break;
		if (i >= j) break;
		swapD(&arr[i], &arr[j]);
		//for (int i = 0; i < 15; i++) printf("%lf ", arr[i]);
		//printf("\n");
	}
	swapD(&arr[right], &arr[i]);
	//for (int i = 0; i < 15; i++) printf("%lf ", arr[i]);
	//printf("\n");
	return i;
}