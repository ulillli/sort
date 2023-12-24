#include "double.h"

void merge(double* arr, double* arr_new, int left, int middle, int right);
void mergeSort(double* arr, double* arr_new, int left, int right);

void mergeSort(double* arr, double* arr_new, int left, int right) {
	int  middle = (left + right) / 2;
	if (right - left <= 1) return;
	mergeSort(arr, arr_new, left, middle);
	mergeSort(arr, arr_new, middle, right);
	merge(arr, arr_new, left, middle, right);
}

void merge(double* arr, double* arr_new, int left, int middle, int right) {
	double* p1 = &arr[left], * p2 = &arr[middle], * p3 = &arr_new[left];
	while ((p1 < &arr[middle]) && (p2 < &arr[right])) {
		if (*p1 <= *p2) {
			*p3 = *p1;
			p3++;
			p1++;
		}
		else {
			*p3 = *p2;
			p3++;
			p2++;
		}
	}
	while (p1 < &arr[middle]) {
		*p3 = *p1;
		p3++;
		p1++;
	}
	while (p2 < &arr[right]) {
		*p3 = *p2;
		p3++;
		p2++;
	}
	for (int i = left; i < right; i++) arr[i] = arr_new[i];
}