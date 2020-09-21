/**
 *  @Copyright (C) 2020 March. All rights reserved.
 *  @license   GNU General Public License (GPL)
 *  @author	   March
 *  @email	   345916208@qq.com
 *  @file	   main.cpp
 *  @brief	   内排序的C++实现主文件
 *  @version   1.0
 *  @date	   2020-08-29
 */

#include"stdafx.h"
#include"sort.h"

int main()
{
	// 示例一：冒泡排序、选择排序、插入排序等
	vector<int> arrs1 = { 5,6,-2,8,9,0,-4,12,0,2,1 }; // 待排序数组1
	int len = arrs1.size();
	cout << "待排序的数组1：";
	for (auto num : arrs1) cout << num << " ";
	cout << "元素个数：" << len << endl;

	BubbleSort(arrs1, len); // 冒泡排序
	SelectionSort(arrs1, len); // 选择排序
	InsertSort(arrs1, len); // 插入排序
	ShellSort(arrs1, len); // 希尔排序
	HeapSort(arrs1, len); // 堆排序
	MergeSort(arrs1, len, 0); // 归并排序，mode：0迭代版，1递归版
	QuickSort(arrs1, len, 1); // 快速排序，mode：0改进版，1递归版
	CountSort(arrs1, len, 1); // 计数排序，mode：0常规版，1稳定版

	// 示例二：桶排序
	vector<double> arrs2 = { 0.2,0.007,0.3,0,0.5,0.003,0.05,0.1 }; // 待排序数组2
	int len2 = arrs2.size();
	cout << endl << "待排序的数组2：";
	for (auto num : arrs2) cout << num << " ";
	cout << "元素个数：" << len2 << endl;

	BucketSort(arrs2, len2); // 桶排序

	// 示例三：基数排序
	vector<string> arrs3 = { "a", "ba","bc","abc","aca" ,"bbc","ad" ,"adc" }; // 待排序数组3
	int len3 = arrs3.size();
	cout << endl << "待排序的数组3：";
	for (auto num : arrs3) cout << num << " ";
	cout << "元素个数：" << len3 << endl;

	CardinalSort(arrs3, len3); // 基数排序

	sort(arrs3.begin(), arrs3.end());
	cout << "正确排序结果：";
	for (auto num : arrs3) cout << num << " "; cout << endl;

	return 0;
}
