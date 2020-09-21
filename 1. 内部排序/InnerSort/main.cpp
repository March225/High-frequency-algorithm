/**
 *  @Copyright (C) 2020 March. All rights reserved.
 *  @license   GNU General Public License (GPL)
 *  @author	   March
 *  @email	   345916208@qq.com
 *  @file	   main.cpp
 *  @brief	   �������C++ʵ�����ļ�
 *  @version   1.0
 *  @date	   2020-08-29
 */

#include"stdafx.h"
#include"sort.h"

int main()
{
	// ʾ��һ��ð������ѡ�����򡢲��������
	vector<int> arrs1 = { 5,6,-2,8,9,0,-4,12,0,2,1 }; // ����������1
	int len = arrs1.size();
	cout << "�����������1��";
	for (auto num : arrs1) cout << num << " ";
	cout << "Ԫ�ظ�����" << len << endl;

	BubbleSort(arrs1, len); // ð������
	SelectionSort(arrs1, len); // ѡ������
	InsertSort(arrs1, len); // ��������
	ShellSort(arrs1, len); // ϣ������
	HeapSort(arrs1, len); // ������
	MergeSort(arrs1, len, 0); // �鲢����mode��0�����棬1�ݹ��
	QuickSort(arrs1, len, 1); // ��������mode��0�Ľ��棬1�ݹ��
	CountSort(arrs1, len, 1); // ��������mode��0����棬1�ȶ���

	// ʾ������Ͱ����
	vector<double> arrs2 = { 0.2,0.007,0.3,0,0.5,0.003,0.05,0.1 }; // ����������2
	int len2 = arrs2.size();
	cout << endl << "�����������2��";
	for (auto num : arrs2) cout << num << " ";
	cout << "Ԫ�ظ�����" << len2 << endl;

	BucketSort(arrs2, len2); // Ͱ����

	// ʾ��������������
	vector<string> arrs3 = { "a", "ba","bc","abc","aca" ,"bbc","ad" ,"adc" }; // ����������3
	int len3 = arrs3.size();
	cout << endl << "�����������3��";
	for (auto num : arrs3) cout << num << " ";
	cout << "Ԫ�ظ�����" << len3 << endl;

	CardinalSort(arrs3, len3); // ��������

	sort(arrs3.begin(), arrs3.end());
	cout << "��ȷ��������";
	for (auto num : arrs3) cout << num << " "; cout << endl;

	return 0;
}
