#pragma once
#include"stdafx.h"

vector<int> BubbleSort(vector<int> arrs, int len); // ð������
vector<int> SelectionSort(vector<int> arrs, int len); // ��ѡ������
vector<int> InsertSort(vector<int> arrs, int len); // �򵥲�������
vector<int> ShellSort(vector<int> arrs, int len); // ϣ������

void heapAdjust(vector<int>& arrs, int parent, int curLen); // ������֮�ѵ���
vector<int> HeapSort(vector<int> arrs, int len); // ������

void merge(vector<int>& arrs, int left, int mid, int right);// �鲢���򣨵ݹ�棩֮�ϲ��������ϲ�[left,mid]��[mid+1,right]��
void mergeSortByRecur(vector<int>& arrs, int left, int right); // �鲢���򣨵ݹ�棩
void mergeSortByIter(vector<int>& arrs, int len); // �鲢���򣨵����棩
vector<int> MergeSort(vector<int> arrs, int len, char mode); // �鲢����mode��0�����棬1�ݹ��

int partition(vector<int>& arrs, int left, int right); // �������򣨵ݹ�棩֮�ָ������������Ԫ��Ϊ��׼��������ָ�������֣�
void quickSortByRecur(vector<int>& arrs, int left, int right); // �������򣨵ݹ�棩
vector<int> QuickSort(vector<int> arrs, int len, char mode); // ��������mode��0�Ľ��棬1�ݹ��

void generalCountSort(vector<int>& arrs, int len); // �������򳣹��
void stableCountSort(vector<int>& arrs, int len); // ���������ȶ���
vector<int> CountSort(vector<int> arrs, int len, char mode); // ��������mode��0����棬1�ȶ���

vector<double> BucketSort(vector<double> arrs, int len); // Ͱ����

int getCharAscii(string str, int k); // ������������������ȡ�ַ�����kλ�ַ�����Ӧ��ascii�����
vector<string> CardinalSort(vector<string> arrs, int len); // ��������

