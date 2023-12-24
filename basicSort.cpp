#include "double.h"

void selectionSort(double* arr, double* empty1, int n, int empty2); //сортировка выбором 
void insertSort(double* arr, double* empty1, int n, int empty2); //сортировка вставками
void bubbleSort(double* arr, double* empty1, int n, int empty2); //сортировка пузырьком

void selectionSort(double* arr, double* empty1, int n, int empty2) {
	for (int i = 0; i < n; i++) {
		int minIndex = i;
		for (int j = i + 1; j < n; j++) if (arr[j] < arr[minIndex]) minIndex = j;
		swapD(&arr[i], &arr[minIndex]);
	}
}
void insertSort(double* arr, double* empty1, int n, int empty2) {
	for (int i = 0; i < n - 1; i++) {
		double key = arr[i + 1];
		for (int j = i; j >= 0; j--) {
			if (arr[j] > key)swapD(&arr[j], &arr[j + 1]);
			else break;
		}
	}
}
void bubbleSort(double* arr, double* empty1, int n, int empty2) {
	for (int i = 0; i < n; i++) {
		bool flag = false;
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swapD(&arr[j], &arr[j + 1]);
				flag = true;
			}
		}
		if (!flag) break;
	}
}