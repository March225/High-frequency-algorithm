#include"sort.h"

// ð������
vector<int> BubbleSort(vector<int> arrs, int len) {
	cout << "ð����������";
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

// ��ѡ������
vector<int> SelectionSort(vector<int> arrs, int len) {
	cout << "ѡ����������";
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

// �򵥲�������
vector<int> InsertSort(vector<int> arrs, int len) {
	for (int i = 1; i < len; ++i) {
		int key = arrs[i];
		int j = i - 1;
		// ������ǰ����ΪС���ڳ�λ��
		while (j >= 0 && arrs[j] > key) {
			arrs[j + 1] = arrs[j];
			--j;
		}
		arrs[j + 1] = key;
	}
	cout << "������������";
	for (auto num : arrs) cout << num << " "; cout << endl;
	return arrs;
}

// ϣ������
vector<int> ShellSort(vector<int> arrs, int len) {
	int gap = len;
	while (gap > 1) {
		//��1��Ϊ�˲���gapΪ0������ gap > 0 �����½���ѭ������ gap = n / 2 ���Բ��ü�1����Ϊ0����1��Ԫ�ز���Ҫ����
		gap = gap / 3 + 1;
		// ����������ÿ������м򵥲�������
		for (int i = gap; i < len; ++i) {
			int key = arrs[i];
			int j = 0;
			for (j = i - gap; j >= 0 && arrs[j] > key; j -= gap)
				arrs[j + gap] = arrs[j];
			arrs[j + gap] = key;
		}
	}
	cout << "ϣ����������";
	for (auto num : arrs) cout << num << " "; cout << endl;
	return arrs;
}

// ������֮���µ�����������ɾ��Ԫ�أ�
void heapAdjustDown(vector<int>& arrs, int parent, int curLen) {
	int curParent = arrs[parent];
	int child = 2 * parent + 1; // ����
	while (child < curLen) {  // ���Ӳ����ڣ�����ѭ��
		if (child + 1 < curLen && arrs[child] < arrs[child + 1])
			++child;       // �Һ��ӵ��±�
		if (curParent < arrs[child]) {
			// ��ֵ���Ǹ���㣬��ֵ�ϸ�����Сֵ�ڳ��ռ䣬���Ƽ򵥲�������(��ֵ����)
			arrs[parent] = arrs[child];
			parent = child;
			// ������������Ϊ����������б�curParent��ģ�curParent��Ҫ�����³�
			child = 2 * parent + 1;
		}
		else break;
	}
	// ������������ʱ��pλ�ü�ΪcurParentӦ���ڵ�λ��
	arrs[parent] = curParent;
}

// ������
vector<int> HeapSort(vector<int> arrs, int len) {
	//�����ѣ�����ײ�ĸ��ڵ㿪ʼ
	for (int i = len / 2 - 1; i >= 0; --i)
		heapAdjustDown(arrs, i, len);
	for (int i = len - 1; i > 0; --i) {
		swap(arrs[0], arrs[i]);
		heapAdjustDown(arrs, 0, i);
	}
	cout << "������Ľ����";
	for (auto num : arrs) cout << num << " "; cout << endl;
	return arrs;
}

// �鲢���򣨵ݹ�棩֮�ϲ��������ϲ�[left,mid]��[mid+1,right]��
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

// �鲢���򣨵ݹ�棩
void mergeSortByRecur(vector<int>& arrs, int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		mergeSortByRecur(arrs, left, mid);
		mergeSortByRecur(arrs, mid + 1, right);
		merge(arrs, left, mid, right);
	}
}

// �鲢���򣨵����棩
void mergeSortByIter(vector<int>& arrs, int len) {
	// seg��1 2 4 8����ʾ�ϲ�ʱÿ������Ĵ�С
	for (int seg = 1; seg < len; seg *= 2) {
		// ��seg������������beg
		for (int beg = 0; beg < len; beg += seg * 2) {
			// ��seg��beg����left��right��mid������merge�������������
			int left = beg, right = min(left + seg * 2 - 1, len - 1);
			int mid = min(left + seg - 1, len - 1);
			merge(arrs, left, mid, right);
		}
	}
}

// �鲢����mode��0�����棬1�ݹ��
vector<int> MergeSort(vector<int> arrs, int len, char mode) {
	if (mode) {
		mergeSortByRecur(arrs, 0, len - 1); // �ݹ��
		cout << "�鲢����ݹ飺";
	}
	else {
		mergeSortByIter(arrs, len); // ������
		cout << "�鲢���������";
	}

	for (auto num : arrs) cout << num << " "; cout << endl;
	return arrs;
}

// �������򣨵ݹ�棩֮�ָ������������Ԫ��Ϊ��׼��������ָ�������֣�
int partition(vector<int>& arrs, int left, int right) {
	int pivot = arrs[left]; // ȡ��һ��λ�õ�Ԫ����Ϊ����Ԫ��
	int l = left, r = right;
	while (l < r) {
		// �ұ������ӽ���ߣ�����ѭ������
		while (l < r && arrs[r] > pivot) --r; arrs[l] = arrs[r];
		while (l < r && arrs[l] <= pivot) ++l; arrs[r] = arrs[l];
	}
	// ��pivot�������м䣬��ɷָ��Ϊ���ұ������ӽ���ߣ�����������arrs[l]��
	arrs[l] = pivot;
	return l;
}

// �������򣨵ݹ�棩
void quickSortByRecur(vector<int>& arrs, int left, int right) {
	if (left < right) {
		int pivotIdx = partition(arrs, left, right);
		quickSortByRecur(arrs, left, pivotIdx - 1);
		quickSortByRecur(arrs, pivotIdx + 1, right);
	}
}

//// �������򣨸Ľ��棩
//void quickSortImproved(vector<int>& arrs, int len) {

//}

// ��������mode��0�Ľ��棬1�ݹ��
vector<int> QuickSort(vector<int> arrs, int len, char mode) {
	if (mode) {
		quickSortByRecur(arrs, 0, len - 1); // �ݹ��
		cout << "��������ݹ飺";
	}
	// 	else {
	// 		quickSortImproved(arrs, len); // �Ľ���
	// 		cout << "��������Ľ���";
	// 	}

	for (auto num : arrs) cout << num << " "; cout << endl;
	return arrs;
}

// �������򳣹��
void generalCountSort(vector<int>& arrs, int len) {
	// 1.�õ�ԭʼ��������ֵ����Сֵ������ͳ���������賤��n
	int minVal = arrs[0];
	int maxVal = arrs[0];
	for (auto num : arrs) {
		maxVal = num > maxVal ? num : maxVal;
		minVal = num < minVal ? num : minVal;
	}
	int n = maxVal - minVal + 1;

	// 2.����ͳ�����鲢ͳ�ƶ�ӦԪ�ظ���
	vector<int> countArrs(n, 0);
	for (auto num : arrs)
		++countArrs[num - minVal];

	// 3.����ͳ�����飬������
	int k = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < countArrs[i]; ++j) {
			arrs[k++] = minVal + i;
		}
	}
}

// ���������ȶ���
void stableCountSort(vector<int>& arrs, int len) {
	// 1.�õ�ԭʼ��������ֵ����Сֵ������ͳ���������賤��n
	int minVal = arrs[0];
	int maxVal = arrs[0];
	for (auto num : arrs) {
		maxVal = num > maxVal ? num : maxVal;
		minVal = num < minVal ? num : minVal;
	}
	int n = maxVal - minVal + 1;

	// 2.����ͳ�����鲢ͳ�ƶ�ӦԪ�ظ���
	vector<int> countArrs(n, 0);
	for (auto num : arrs)
		++countArrs[num - minVal];

	// 3.��ͳ��������б��Σ���ǰͳ��ֵ = ��ǰͳ��ֵ + ǰһ��ͳ��ֵ
	for (int i = 1; i < n; ++i)
		countArrs[i] += countArrs[i - 1];

	// 4.�������ԭʼ���飬��ͳ�������ҵ���ȷλ�ã�������������
	vector<int> tmp(arrs); // ����ԭʼ����Ϊtmp
	for (int i = len - 1; i >= 0; --i) {
		int idx = countArrs[tmp[i] - minVal] - 1; // Ԫ��tmp[i]��ԭʼ������ʵ��λ�õ�����
		arrs[idx] = tmp[i]; // ��������idx����Ԫ��ֵ
		--countArrs[tmp[i] - minVal]; // �����Լ�1����֤�´�������ͬԪ��ʱ��λ����tmp[i]֮ǰ����ѭ��ԭ���Ĺ���˳������������ȶ���
	}
}

// ��������mode��0����棬1�ȶ���
vector<int> CountSort(vector<int> arrs, int len, char mode) {
	if (mode) {
		cout << "���������ȶ���";
		if (len == 0) return arrs;
		stableCountSort(arrs, len); // �ȶ���	
	}
	else {
		cout << "�������򳣹棺";
		if (len == 0) return arrs;
		generalCountSort(arrs, len); // �����	
	}

	for (auto num : arrs) cout << num << " "; cout << endl;
	return arrs;
}

// Ͱ����
vector<double> BucketSort(vector<double> arrs, int len) {
	cout << "Ͱ����Ľ����";
	if (len == 0) return arrs;

	// 1.�õ�ԭʼ��������ֵ����Сֵ���������ֵd
	double minVal = arrs[0];
	double maxVal = arrs[0];
	for (auto num : arrs) {
		maxVal = num > maxVal ? num : maxVal;
		minVal = num < minVal ? num : minVal;
	}
	double d = maxVal - minVal;

	// 2.��ʼ��Ͱ������ԭʼ���飬��ÿ��Ԫ�ط���Ͱ��
	vector<list<double>> bucket(len, list<double>(0));
	double interval = d / ((double)len - 1); // ������
	for (int i = 0; i < len; ++i) {
		int buck_idx = int((arrs[i] - minVal) / interval); // arrs[i]����Ͱ������
		bucket[buck_idx].emplace_back(arrs[i]);
	}

	// 3.��ÿ��ͨ�ڲ���������ͬʱ����ԭʼ����
	int idx = 0;
	for (int i = 0; i < len; ++i) {
		bucket[i].sort();
		for (auto num : bucket[i])
			arrs[idx++] = num;
	}

	for (auto num : arrs) cout << num << " "; cout << endl;
	return arrs;
}

// ������������������ȡ�ַ�����kλ�ַ�����Ӧ��ascii�����
int getCharAscii(string str, int k) {
	int n = str.size();
	if (n < k) return 0;
	else return int(str[k]);
}

// ��������
vector<string> CardinalSort(vector<string> arrs, int len) {
	const int kAsciiRange = 128; // ����ascii���ȡֵ��Χ

	// ��ȡ�������ַ�������󳤶�
	int maxLen = 0;
	for (auto str : arrs) maxLen = max(maxLen, int(str.size()));

	vector<string> sortedArrs(len); // ���������飬���ڴ洢ÿһ�ΰ�λ�������ʱ���
	// �Ӹ�λ��ʼ�Ƚϣ�һֱ�Ƚϵ����λ
	for (int i = maxLen - 1; i >= 0; --i) {
		//��������Ĺ��̣��ֳ�������

		// 1.����ͳ�����鲢ͳ�ƶ�ӦԪ�ظ���
		vector<int> countArrs(kAsciiRange, 0);
		for (int j = 0; j < len; ++j) {
			int asciiIdx = getCharAscii(arrs[j], i);
			++countArrs[asciiIdx];
		}

		// 2.��ͳ��������б��Σ���ǰͳ��ֵ = ��ǰͳ��ֵ + ǰһ��ͳ��ֵ
		for (int j = 1; j < kAsciiRange; ++j)
			countArrs[j] += countArrs[j - 1];

		// 3.�������ԭʼ���飬��ͳ�������ҵ���ȷλ�ã�������������
		for (int j = len - 1; j >= 0; --j) {
			int asciiIdx = getCharAscii(arrs[j], i);
			sortedArrs[--countArrs[asciiIdx]] = arrs[j];
		}

		//��һ��������Ҫ����һ�ֵ�������Ϊ��������˰ѽ�����Ƹ�ԭʼ����arrs
		arrs = sortedArrs;
	}

	cout << "������������";
	for (auto num : arrs) cout << num << " "; cout << endl;
	return arrs;
}


22.32

