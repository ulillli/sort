#include "double.h"
#include "int.h"

void start(int n);

int main(int argc, char ** argv) {
	//visualization();
	int i = 1;
	while (argv[i] != "") {
		int a = atoi(argv[i]);
		printf("%d \n", a);
		start(a);
		i++;
	}
}

void start(int n) { 
	char arr[][30] = { "BubbleSort","SelectionSort","InsertSort","QuickSort", "MergeSort" };
	void (* sortD[5]) (double*, double*, int, int) = {bubbleSort,selectionSort,insertSort,mergeSort,quickSort};
	void (*sortI[1]) (int*, int) = {radixSort};
	double mintime = 100000;
	for (int i = 0; i < 5; i++) {
		printf("%s\n", arr[i]);
		mintime = 100000;
		minTimeD(&mintime, n, sortD[i]);
		printf("MINTIME             %lf\n\n", mintime);
	}
	printf("Radix Sort\n");
	mintime = 100000;
	minTimeI(&mintime, n, sortI[0]);
	printf("MINTIME             %lf\n", mintime);
}
void chooseSort(pFD sort, int S) {
	switch (S) {
	case 1:
		sort = bubbleSort;
		break;
	case 2:
		sort = selectionSort;
		break;
	case 3:
		sort = insertSort;
		break;
	case 4:
		sort= quickSort;
		break;
	case 5:
		sort= mergeSort;
		break;
	default:
		break;
	}
}

