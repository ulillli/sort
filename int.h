#pragma once
#include "double.h"
#include "radixSort.h"
typedef	void (*pFI) (int*, int);

void minTimeI(double* min_time, int n, pFI sort); //���������� ������������ ������� ��� ������� int ��� 3-� ��������
void uniformI(int* arr, int n, int j); //���������� ������� ����������� �������������� �������

void copyI(int* arr, int* arr_new, int n); //����������� ���������� �������
void verificationI(int* arr, int* arr_new, int n); //�������� �� ������ ����������
void seeArrI(int* arr, int n); //������������ �������


