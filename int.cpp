#include "double.h"
#include "radixSort.h"

void minTimeI(double* min_time, int n, pFI sort); //���������� ������������ ������� ��� ������� int ��� 3-� ��������
void uniformI(int * arr, int n, int j); //���������� ������� ����������� �������������� �������

void copyI(int* arr, int * arr_new, int n); //����������� ���������� �������
void verificationI(int* arr, int * arr_new, int n); //�������� �� ������ ����������
void seeArrI(int * arr, int n); //������������ �������

void minTimeI(double* min_time, int n, pFI sort) {
	for (int i = 0; i < 3; i++) {
		int* arr = (int*)malloc(n * sizeof(int));
		int* buf = (int*)malloc(n * sizeof(int)); //������ ��� �������� 

		uniformI(arr, n, i); //���������� �������� �������

		copyI(arr, buf, n);//���������� ������� ��� �������� 
		double time;
		clock_t start = clock();
		sort(arr, n);
		clock_t stop = clock();
		verificationI(arr, buf, n);

		time = ((double)(stop - start)) / CLOCKS_PER_SEC;
		if (time < *min_time) *min_time = time;
		//seeArrI(arr, n); //�������� ���������������� �������

		free(arr);
		free(buf);
	}
}
void copyI(int * arr, int * arr_new, int n) {
	for (int i = 0; i < n; i++)arr_new[i] = arr[i];
}

void verificationI(int* arr, int* arr_new, int n) {
	qsort(arr_new, n, sizeof(int), cmp);
	//seeArr(arr_new, n);
	bool flag = true;
	for (int i = 0; i < n; i++) {
		if (arr_new[i] != arr[i]) {
			flag = false;
			printf("Error\n");
			break;
		}
	}
	if (flag) printf("Not error\n");
}

void seeArrI(int * arr, int n) {
	for (int i = 0; i < n; i++) printf("%d", arr[i]);
	printf("\n");
}

void uniformI(int * arr, int n, int j) {
	srand(time(NULL) + j);
	for (int i = 0; i < n; i++) {
		arr[i] = rand();
	}
}
