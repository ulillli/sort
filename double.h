#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "basicSort.h"
#include "quickSort.h"
#include "mergeSort.h"

typedef void (*pFD) (double*, double*, int, int);

void visualization(); //визуализация выбора сортировки

void minTimeD(double* min_time, int n, pFD sort); //нахождение минимального времени для массива double из 3-х запусков
void swapD(double* el1, double* el2);
void uniformD(double* arr, int n, int j); //заполнение массива равномернно распределёнными данными

void copyD(double* arr, double* arr_new, int n); //копирование созданного массива
void verificationD(double* arr, double* arr_new, int n); //проверка на верную сортировку
void seeArrD(double* arr, int n); //визуализация массива

int cmp(const void* a, const void* b);
