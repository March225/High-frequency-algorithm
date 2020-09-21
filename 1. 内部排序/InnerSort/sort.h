#pragma once
#include"stdafx.h"

vector<int> BubbleSort(vector<int> arrs, int len); // 冒泡排序
vector<int> SelectionSort(vector<int> arrs, int len); // 简单选择排序
vector<int> InsertSort(vector<int> arrs, int len); // 简单插入排序
vector<int> ShellSort(vector<int> arrs, int len); // 希尔排序

void heapAdjust(vector<int>& arrs, int parent, int curLen); // 堆排序之堆调整
vector<int> HeapSort(vector<int> arrs, int len); // 堆排序

void merge(vector<int>& arrs, int left, int mid, int right);// 归并排序（递归版）之合并操作（合并[left,mid]与[mid+1,right]）
void mergeSortByRecur(vector<int>& arrs, int left, int right); // 归并排序（递归版）
void mergeSortByIter(vector<int>& arrs, int len); // 归并排序（迭代版）
vector<int> MergeSort(vector<int> arrs, int len, char mode); // 归并排序，mode：0迭代版，1递归版

int partition(vector<int>& arrs, int left, int right); // 快速排序（递归版）之分割操作（以中轴元素为基准，将数组分割成三部分）
void quickSortByRecur(vector<int>& arrs, int left, int right); // 快速排序（递归版）
vector<int> QuickSort(vector<int> arrs, int len, char mode); // 快速排序，mode：0改进版，1递归版

void generalCountSort(vector<int>& arrs, int len); // 计数排序常规版
void stableCountSort(vector<int>& arrs, int len); // 计数排序稳定版
vector<int> CountSort(vector<int> arrs, int len, char mode); // 计数排序，mode：0常规版，1稳定版

vector<double> BucketSort(vector<double> arrs, int len); // 桶排序

int getCharAscii(string str, int k); // 基数排序辅助函数：获取字符串第k位字符所对应的ascii码序号
vector<string> CardinalSort(vector<string> arrs, int len); // 基数排序

