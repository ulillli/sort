#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "basicSort.h"
#include "quickSort.h"
#include "mergeSort.h"

typedef void (*pFD) (double*, double*, int, int);

void visualization(); //������������ ������ ����������

void minTimeD(double* min_time, int n, pFD sort); //���������� ������������ ������� ��� ������� double �� 3-� ��������
void swapD(double* el1, double* el2);
void uniformD(double* arr, int n, int j); //���������� ������� ����������� �������������� �������

void copyD(double* arr, double* arr_new, int n); //����������� ���������� �������
void verificationD(double* arr, double* arr_new, int n); //�������� �� ������ ����������
void seeArrD(double* arr, int n); //������������ �������

int cmp(const void* a, const void* b);
