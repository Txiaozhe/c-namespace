#include "stdio.h"
#include "stdlib.h"
#include "time.h"
// 插入排序
void insert_sort(int *a, int length) {
    int tmp;
    int i, j;
    for (i = 0; i < length; ++i) {
        for (tmp = a[i], j = i -1; i >= 0 && a[j] > tmp; j--) {
            a[j + 1] = a[j];
        }
        a[j + 1] = tmp;
    }
}

// 快速排序，挖坑填数
int partion(int *a, int start, int end) {
	int i = start, j = end;
	int tmp = a[i]; // 越界检查

	while(i < j) {
		// 从后向前扫描，找到第一个小于tmp的值，填入a[i]
		while(i < j && a[j] >= tmp) {
			j--;
		}
		if (i < j) { // 找到了
			a[i++] = a[j];
		}

		// 从左向右扫描，找一个大于tmp的数，填入a[j]
		while(i < j && a[i] < tmp) {
			i++;
		}
		if (i < j) {
			a[j++] = a[i];
		}
	}

	// 扫描结束, i == j
	a[i] = tmp;

	return i;
}

void quick_sort(int *a, int left, int right) {
	if (left < right) {
		int i = partion(a, left, right);
		quick_sort(a, left, i - 1);
		quick_sort(a, i + 1, right);
	}
}

#define Max_Number 500000

int main() {
    int a[Max_Number];
	for (int i = 0; i < Max_Number; ++i)
	{
		a[i]=rand() % Max_Number;
	}

	clock_t start, finish;

    start = clock();
	// merge_sort(a,sizeof(a)/sizeof(int));    // 0.002s,可以看到，归并排序还是很快的
	//heap_sort(a,sizeof(a)/sizeof(int));  // 有buggggggg
	quick_sort(a, 0, sizeof(a) / sizeof(int) - 1); // 0.01s
	// insert_sort(a, sizeof(a) / sizeof(int));
	//select_sort(a,sizeof(a)/sizeof(int));   // 5.3s
	//bubble_sort(a,sizeof(a)/sizeof(int));    // 12.5s
	finish = clock();

	printf("after sort:\n");
	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
	{
		printf("  %d  ", a[i]);
	}
	printf("time eclipse: %.6f sec\n", (double)(finish - start) / CLOCKS_PER_SEC); // CLOCKS_PER_SEC 1000 clock()是毫秒

	return 0;
}
