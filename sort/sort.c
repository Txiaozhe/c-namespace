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
	//quicksort(a,0,sizeof(a)/sizeof(int)-1); // 0.01s
	insert_sort(a, sizeof(a) / sizeof(int));
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
