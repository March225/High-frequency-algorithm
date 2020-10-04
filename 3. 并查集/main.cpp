/**
 *  @Copyright (C) 2020 March. All rights reserved.
 *  @license   GNU General Public License (GPL)
 *  @author	   March
 *  @email	   345916208@qq.com
 *  @file	   main.cpp
 *  @brief	   ʵ�ֲ��鼯���Ż���1.�����Ĵ�С���кϲ���2.·��ѹ����
 *  @version   1.0
 *  @date	   2020-08-25
 */

#include "stdafx.h"

class UnionFind {
private:
	int count_; // ��ͨ��������
	vector<int> parent; // �洢һ����
	vector<int> size; // ��¼���Ĵ�С�������˸�������ڵ��������Ľ������

public:
	UnionFind(int n) : count_(n), parent(vector<int>(n)), size(vector<int>(n, 1)) {
		for (int i = 0; i < n; ++i)
			parent[i] = i;
	}

	// �ݹ����Ҹ���㣨���µ�·��ѹ����
	int find(int x) {
		return x == parent[x] ? x : (parent[x] = find(parent[x]));
	}

	//// ��������Ҹ���㣨�������µ�·��ѹ����
	//int find(int x) {
	//	while (parent[x] != x) {
	//		// ����·��ѹ��
	//		parent[x] = parent[parent[x]];
	//		x = parent[x];
	//	}
	//	return x;
	//}

	// �����Ĵ�С���кϲ�
	void to_union(int x1, int x2)
	{
		int f1 = find(x1);
		int f2 = find(x2);
		// ����������ͨ�ģ�ֱ�ӷ���
		if (f1 == f2) return;

		// С���ӵ��������棬��ƽ��
		if (size[f1] > size[f2]) {
			parent[f2] = f1;
			size[f1] += size[f2];
		}
		else {
			parent[f1] = f2;
			size[f2] += size[f1];
		}
		// ��ͨ����1
		--count_;
	}

	// �ж�x1��x2�Ƿ���ͨ
	bool connected(int x1, int x2)
	{
		return find(x1) == find(x2);
	}

	// ������ͨ��������
	int count() {
		return count_;
	}
};
int main() {
	UnionFind uf(10);

	uf.to_union(0, 1);
	uf.to_union(2, 3);
	cout << "��ͨ����������" << uf.count() << endl;

	return 0;
}