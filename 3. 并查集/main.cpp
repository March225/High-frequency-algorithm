/**
 *  @Copyright (C) 2020 March. All rights reserved.
 *  @license   GNU General Public License (GPL)
 *  @author	   March
 *  @email	   345916208@qq.com
 *  @file	   main.cpp
 *  @brief	   实现并查集（优化：1.按树的大小进行合并；2.路径压缩）
 *  @version   1.0
 *  @date	   2020-08-25
 */

#include "stdafx.h"

class UnionFind {
private:
	int count_; // 连通分量个数
	vector<int> parent; // 存储一棵树
	vector<int> size; // 记录树的大小（包含此根结点在内的整棵树的结点数）

public:
	UnionFind(int n) : count_(n), parent(vector<int>(n)), size(vector<int>(n, 1)) {
		for (int i = 0; i < n; ++i)
			parent[i] = i;
	}

	// 递归版查找根结点（极致的路径压缩）
	int find(int x) {
		return x == parent[x] ? x : (parent[x] = find(parent[x]));
	}

	//// 迭代版查找根结点（不够极致的路径压缩）
	//int find(int x) {
	//	while (parent[x] != x) {
	//		// 进行路径压缩
	//		parent[x] = parent[parent[x]];
	//		x = parent[x];
	//	}
	//	return x;
	//}

	// 按树的大小进行合并
	void to_union(int x1, int x2)
	{
		int f1 = find(x1);
		int f2 = find(x2);
		// 本来就是连通的，直接返回
		if (f1 == f2) return;

		// 小树接到大树下面，较平衡
		if (size[f1] > size[f2]) {
			parent[f2] = f1;
			size[f1] += size[f2];
		}
		else {
			parent[f1] = f2;
			size[f2] += size[f1];
		}
		// 连通数减1
		--count_;
	}

	// 判断x1和x2是否连通
	bool connected(int x1, int x2)
	{
		return find(x1) == find(x2);
	}

	// 返回连通分量个数
	int count() {
		return count_;
	}
};
int main() {
	UnionFind uf(10);

	uf.to_union(0, 1);
	uf.to_union(2, 3);
	cout << "连通分量个数：" << uf.count() << endl;

	return 0;
}