#pragma once
#include "double.h"
#include "radixSort.h"
typedef	void (*pFI) (int*, int);

void minTimeI(double* min_time, int n, pFI sort); //нахождение минимального времени для массива int для 3-х запусков
void uniformI(int* arr, int n, int j); //заполнение массива равномернно распределёнными данными

void copyI(int* arr, int* arr_new, int n); //копирование созданного массива
void verificationI(int* arr, int* arr_new, int n); //проверка на верную сортировку
void seeArrI(int* arr, int n); //визуализация массива


