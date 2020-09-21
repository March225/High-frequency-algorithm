#include"sort.h"

// 冒泡排序
vector<int> BubbleSort(vector<int> arrs, int len) {
	cout << "冒泡排序结果：";
	for (int i = 0; i < len; ++i) {
		for (int j = len - 1; j > i; --j) {
			if (arrs[j] < arrs[j - 1])
				swap(arrs[j], arrs[j - 1]);
		}
		cout << arrs[i] << " ";
	}
	cout << endl;
	return arrs;
}

// 简单选择排序
vector<int> SelectionSort(vector<int> arrs, int len) {
	cout << "选择排序结果：";
	int min_idx = 0;
	for (int i = 0; i < len; ++i) {
		min_idx = i;
		for (int j = i + 1; j < len; ++j)
			min_idx = arrs[j] < arrs[min_idx] ? j : min_idx;
		if (min_idx != i) swap(arrs[min_idx], arrs[i]);
		cout << arrs[i] << " ";
	}
	cout << endl;
	return arrs;
}

// 简单插入排序
vector<int> InsertSort(vector<int> arrs, int len) {
	for (int i = 1; i < len; ++i) {
		int key = arrs[i];
		int j = i - 1;
		// 大数在前，则为小数腾出位置
		while (j >= 0 && arrs[j] > key) {
			arrs[j + 1] = arrs[j];
			--j;
		}
		arrs[j + 1] = key;
	}
	cout << "插入排序结果：";
	for (auto num : arrs) cout << num << " "; cout << endl;
	return arrs;
}

// 希尔排序
vector<int> ShellSort(vector<int> arrs, int len) {
	int gap = len;
	while (gap > 1) {
		//加1是为了不让gap为0，能在 gap > 0 条件下进入循环，而 gap = n / 2 可以不用加1，因为0个或1个元素不需要排序
		gap = gap / 3 + 1;
		// “轮流”对每个组进行简单插入排序
		for (int i = gap; i < len; ++i) {
			int key = arrs[i];
			int j = 0;
			for (j = i - gap; j >= 0 && arrs[j] > key; j -= gap)
				arrs[j + gap] = arrs[j];
			arrs[j + gap] = key;
		}
	}
	cout << "希尔排序结果：";
	for (auto num : arrs) cout << num << " "; cout << endl;
	return arrs;
}

// 堆排序之向下调整（常用于删除元素）
void heapAdjustDown(vector<int>& arrs, int parent, int curLen) {
	int curParent = arrs[parent];
	int child = 2 * parent + 1; // 左孩子
	while (child < curLen) {  // 孩子不存在，跳出循环
		if (child + 1 < curLen && arrs[child] < arrs[child + 1])
			++child;       // 右孩子的下标
		if (curParent < arrs[child]) {
			// 大值覆盖父结点，大值上浮，给小值腾出空间，类似简单插入排序(大值右移)
			arrs[parent] = arrs[child];
			parent = child;
			// 迭代子树，因为如果子树中有比curParent大的，curParent还要继续下沉
			child = 2 * parent + 1;
		}
		else break;
	}
	// 迭代结束，这时的p位置即为curParent应该在的位置
	arrs[parent] = curParent;
}

// 堆排序
vector<int> HeapSort(vector<int> arrs, int len) {
	//建立堆，从最底层的父节点开始
	for (int i = len / 2 - 1; i >= 0; --i)
		heapAdjustDown(arrs, i, len);
	for (int i = len - 1; i > 0; --i) {
		swap(arrs[0], arrs[i]);
		heapAdjustDown(arrs, 0, i);
	}
	cout << "堆排序的结果：";
	for (auto num : arrs) cout << num << " "; cout << endl;
	return arrs;
}

// 归并排序（递归版）之合并操作（合并[left,mid]与[mid+1,right]）
void merge(vector<int>& arrs, int left, int mid, int right) {
	vector<int> tmp;
	int i = left, j = mid + 1;
	while (i <= mid && j <= right) {
		if (arrs[i] < arrs[j]) tmp.push_back(arrs[i++]);
		else tmp.push_back(arrs[j++]);
	}
	while (i <= mid)
		tmp.push_back(arrs[i++]);
	while (j <= right)
		tmp.push_back(arrs[j++]);
	for (int k = 0; k < int(tmp.size()); ++k)
		arrs[left + k] = tmp[k];
}

// 归并排序（递归版）
void mergeSortByRecur(vector<int>& arrs, int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		mergeSortByRecur(arrs, left, mid);
		mergeSortByRecur(arrs, mid + 1, right);
		merge(arrs, left, mid, right);
	}
}

// 归并排序（迭代版）
void mergeSortByIter(vector<int>& arrs, int len) {
	// seg：1 2 4 8，表示合并时每个数组的大小
	for (int seg = 1; seg < len; seg *= 2) {
		// 由seg计算数组的起点beg
		for (int beg = 0; beg < len; beg += seg * 2) {
			// 由seg和beg计算left、right和mid，带入merge函数获得排序结果
			int left = beg, right = min(left + seg * 2 - 1, len - 1);
			int mid = min(left + seg - 1, len - 1);
			merge(arrs, left, mid, right);
		}
	}
}

// 归并排序，mode：0迭代版，1递归版
vector<int> MergeSort(vector<int> arrs, int len, char mode) {
	if (mode) {
		mergeSortByRecur(arrs, 0, len - 1); // 递归版
		cout << "归并排序递归：";
	}
	else {
		mergeSortByIter(arrs, len); // 迭代版
		cout << "归并排序迭代：";
	}

	for (auto num : arrs) cout << num << " "; cout << endl;
	return arrs;
}

// 快速排序（递归版）之分割操作（以中轴元素为基准，将数组分割成三部分）
int partition(vector<int>& arrs, int left, int right) {
	int pivot = arrs[left]; // 取第一个位置的元素作为中轴元素
	int l = left, r = right;
	while (l < r) {
		// 右边主动接近左边，进行循环覆盖
		while (l < r && arrs[r] > pivot) --r; arrs[l] = arrs[r];
		while (l < r && arrs[l] <= pivot) ++l; arrs[r] = arrs[l];
	}
	// 把pivot交换到中间，完成分割（因为是右边主动接近左边，所以这里是arrs[l]）
	arrs[l] = pivot;
	return l;
}

// 快速排序（递归版）
void quickSortByRecur(vector<int>& arrs, int left, int right) {
	if (left < right) {
		int pivotIdx = partition(arrs, left, right);
		quickSortByRecur(arrs, left, pivotIdx - 1);
		quickSortByRecur(arrs, pivotIdx + 1, right);
	}
}

//// 快速排序（改进版）
//void quickSortImproved(vector<int>& arrs, int len) {

//}

// 快速排序，mode：0改进版，1递归版
vector<int> QuickSort(vector<int> arrs, int len, char mode) {
	if (mode) {
		quickSortByRecur(arrs, 0, len - 1); // 递归版
		cout << "快速排序递归：";
	}
	// 	else {
	// 		quickSortImproved(arrs, len); // 改进版
	// 		cout << "快速排序改进：";
	// 	}

	for (auto num : arrs) cout << num << " "; cout << endl;
	return arrs;
}

// 计数排序常规版
void generalCountSort(vector<int>& arrs, int len) {
	// 1.得到原始数组的最大值和最小值，计算统计数组所需长度n
	int minVal = arrs[0];
	int maxVal = arrs[0];
	for (auto num : arrs) {
		maxVal = num > maxVal ? num : maxVal;
		minVal = num < minVal ? num : minVal;
	}
	int n = maxVal - minVal + 1;

	// 2.创建统计数组并统计对应元素个数
	vector<int> countArrs(n, 0);
	for (auto num : arrs)
		++countArrs[num - minVal];

	// 3.遍历统计数组，输出结果
	int k = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < countArrs[i]; ++j) {
			arrs[k++] = minVal + i;
		}
	}
}

// 计数排序稳定版
void stableCountSort(vector<int>& arrs, int len) {
	// 1.得到原始数组的最大值和最小值，计算统计数组所需长度n
	int minVal = arrs[0];
	int maxVal = arrs[0];
	for (auto num : arrs) {
		maxVal = num > maxVal ? num : maxVal;
		minVal = num < minVal ? num : minVal;
	}
	int n = maxVal - minVal + 1;

	// 2.创建统计数组并统计对应元素个数
	vector<int> countArrs(n, 0);
	for (auto num : arrs)
		++countArrs[num - minVal];

	// 3.对统计数组进行变形，当前统计值 = 当前统计值 + 前一个统计值
	for (int i = 1; i < n; ++i)
		countArrs[i] += countArrs[i - 1];

	// 4.倒序遍历原始数组，从统计数组找到正确位置，输出到结果数组
	vector<int> tmp(arrs); // 复制原始数组为tmp
	for (int i = len - 1; i >= 0; --i) {
		int idx = countArrs[tmp[i] - minVal] - 1; // 元素tmp[i]在原始数组中实际位置的索引
		arrs[idx] = tmp[i]; // 更新索引idx处的元素值
		--countArrs[tmp[i] - minVal]; // 索引自减1，保证下次遇到相同元素时其位置在tmp[i]之前，遵循了原来的固有顺序，因此排序是稳定的
	}
}

// 计数排序，mode：0常规版，1稳定版
vector<int> CountSort(vector<int> arrs, int len, char mode) {
	if (mode) {
		cout << "计数排序稳定：";
		if (len == 0) return arrs;
		stableCountSort(arrs, len); // 稳定版	
	}
	else {
		cout << "计数排序常规：";
		if (len == 0) return arrs;
		generalCountSort(arrs, len); // 常规版	
	}

	for (auto num : arrs) cout << num << " "; cout << endl;
	return arrs;
}

// 桶排序
vector<double> BucketSort(vector<double> arrs, int len) {
	cout << "桶排序的结果：";
	if (len == 0) return arrs;

	// 1.得到原始数组的最大值和最小值，并计算差值d
	double minVal = arrs[0];
	double maxVal = arrs[0];
	for (auto num : arrs) {
		maxVal = num > maxVal ? num : maxVal;
		minVal = num < minVal ? num : minVal;
	}
	double d = maxVal - minVal;

	// 2.初始化桶，遍历原始数组，将每个元素放入桶中
	vector<list<double>> bucket(len, list<double>(0));
	double interval = d / ((double)len - 1); // 区间跨度
	for (int i = 0; i < len; ++i) {
		int buck_idx = int((arrs[i] - minVal) / interval); // arrs[i]所在桶的索引
		bucket[buck_idx].emplace_back(arrs[i]);
	}

	// 3.对每个通内部进行排序，同时更新原始数组
	int idx = 0;
	for (int i = 0; i < len; ++i) {
		bucket[i].sort();
		for (auto num : bucket[i])
			arrs[idx++] = num;
	}

	for (auto num : arrs) cout << num << " "; cout << endl;
	return arrs;
}

// 基数排序辅助函数：获取字符串第k位字符所对应的ascii码序号
int getCharAscii(string str, int k) {
	int n = str.size();
	if (n < k) return 0;
	else return int(str[k]);
}

// 基数排序
vector<string> CardinalSort(vector<string> arrs, int len) {
	const int kAsciiRange = 128; // 定义ascii码的取值范围

	// 获取待排序字符串的最大长度
	int maxLen = 0;
	for (auto str : arrs) maxLen = max(maxLen, int(str.size()));

	vector<string> sortedArrs(len); // 排序结果数组，用于存储每一次按位排序的临时结果
	// 从个位开始比较，一直比较到最高位
	for (int i = maxLen - 1; i >= 0; --i) {
		//计数排序的过程，分成三步：

		// 1.创建统计数组并统计对应元素个数
		vector<int> countArrs(kAsciiRange, 0);
		for (int j = 0; j < len; ++j) {
			int asciiIdx = getCharAscii(arrs[j], i);
			++countArrs[asciiIdx];
		}

		// 2.对统计数组进行变形，当前统计值 = 当前统计值 + 前一个统计值
		for (int j = 1; j < kAsciiRange; ++j)
			countArrs[j] += countArrs[j - 1];

		// 3.倒序遍历原始数组，从统计数组找到正确位置，输出到结果数组
		for (int j = len - 1; j >= 0; --j) {
			int asciiIdx = getCharAscii(arrs[j], i);
			sortedArrs[--countArrs[asciiIdx]] = arrs[j];
		}

		//下一轮排序需要以上一轮的排序结果为基础，因此把结果复制给原始数组arrs
		arrs = sortedArrs;
	}

	cout << "基数排序结果：";
	for (auto num : arrs) cout << num << " "; cout << endl;
	return arrs;
}


22.32

