#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef int DType;

int randint(int l, int u)
{
    return l + (RAND_MAX*rand() + rand()) % (u-l+1);
}

void swap(DType arr[], int l, int u)
{
    DType tmp = arr[l];
    arr[l] = arr[u];
    arr[u] = tmp;
}
/***********************************************************
找出arr数组中排序后在k位置的DType
其中l为arr的开始下标值，u为arr的结束下标值。
要找的值为在arr中下标k位置的值。
************************************************************/
DType select(DType arr[], int l, int u, int k)
{
	int i, j;
	DType t, temp;
	if (l >= u)
		return;
	swap(arr, l, randint(l, u));
	t = arr[l];
	i = l;
	j = u+1;
	for (;;) {
		do i++; while (i <= u && arr[i] < t);
		do j--; while (arr[j] > t);
		if (i > j)
			break;
		temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
	}
	swap(arr, l, j);
	if (j < k)
		select(arr, j+1, u, k);
	else if (j > k)
		select(arr, l, j-1, k);
    else
		return arr[j];
}

/***************************************************
插入排序
原有数组越有序插入排序算法越快。
***************************************************/
void isort(DType arr[], int n)
{	int i, j;
	DType t;
	for (i = 1; i < n; i++) {
		t = arr[i];
		for (j = i; j > 0 && arr[j-1] > t; j--)
			arr[j] = arr[j-1];
		arr[j] = t;
	}
}

/***************************************************
快速排序
冒泡排序的改进。
此快排只是没有全排，在此排序后应再调用插入排序。
根据《编程珠玑》中统计的cutoff取50最优。
***************************************************/
int cutoff = 50;
void myqsort(DType x[], int l, int u)
{	int i, j;
	DType t, temp;
	if (u - l < cutoff)
		return;
	swap(x, l, randint(l, u));
	t = x[l];
	i = l;
	j = u+1;
	for (;;) {
		do i++; while (i <= u && x[i] < t);
		do j--; while (x[j] > t);
		if (i > j)
			break;
		temp = x[i]; x[i] = x[j]; x[j] = temp;
	}
	swap(x, l, j);
	myqsort(x, l, j-1);
	myqsort(x, j+1, u);
}

/********************************************************
堆排序1 来自《编程珠玑》的随书源码
siftdown：把以l开头的树调换成最大堆；l为开始元素的序号，u为结束元素的序号。
hsort:n为数组x最后一个元素的序号即x长度减1。
********************************************************/
void siftdown(DType x[], int l, int u) /* replace swap with assignments */
{	int i, c, p;
	DType t;
	t = x[l];
	i = l;
	for (;;) {//此循环从上向下把兄弟元素中较大者调换到父元素位置
		c = 2*i;
		if (c > u)
			break;
		if (c+1 <= u && x[c+1] > x[c])
			c++;
		x[i] = x[c];
		i = c;
	}
	x[i] = t;//把开头元素l放到以l开头的树的最后。
	for (;;) {//此循环从下往上从l元素放的位置向上调整。
		p = i/2;
		if (p < l)
			break;
		if (x[p] > x[i])
			break;
		swap(x, p, i);
		i = p;
	}
}
void hsort(DType x[], int n)
{	int i;
	x--;//注意这里
	for (i = n/2; i >= 1; i--)
		siftdown(x, i, n);
	for (i = n; i >= 2; i--) {
		swap(x, 1, i);
		siftdown(x, 1, i-1);
	}
	x++;//注意这里
}

/*********************************************
堆排序2 来自网上
sift：ind为要筛选的节点即从ind为树的开头；len为数组d的长度。
heap_sort：n为数组d的长度。
**********************************************/
void sift(int d[], int ind, int len)
{
        //#置i为要筛选的节点#%
        int i = ind;

        //#c中保存i节点的左孩子#%
        int c = i * 2 + 1; //#+1的目的就是为了解决节点从0开始而他的左孩子一直为0的问题#%

        while(c < len)//#未筛选到叶子节点#%
        {
                //#如果要筛选的节点既有左孩子又有右孩子并且左孩子值小于右孩子#%
                //#从二者中选出较大的并记录#%
                if(c + 1 < len && d[c] < d[c + 1])
                        c++;
                //#如果要筛选的节点中的值大于左右孩子的较大者则退出#%
                if(d[i] > d[c]) break;
                else
                {
                        //#交换#%
                        int t = d[c];
                        d[c] = d[i];
                        d[i] = t;
                        //
                        //#重置要筛选的节点和要筛选的左孩子#%
                        i = c;
                        c = 2 * i + 1;
                }
        }

        return;
}
void heap_sort(int d[], int n)
{
    int i = 0, t;
        //#初始化建堆, i从最后一个非叶子节点开始#%
        for(i = n / 2; i >= 0; i--)
                sift(d, i, n);

        for(i = 0; i < n; i++)
        {
                //#交换#%
                t = d[0];
                d[0] = d[n - i - 1];
                d[n - i - 1] = t;

                //#筛选编号为0 #%
                sift(d, 0, n - i - 1);

        }
}
/**************************************************
选择排序
n为数组x的长度。
**************************************************/
void selsort(DType x[], int n)  /* Selection sort */
{	int i, j;
	for (i = 0; i < n-1; i++)
		for (j = i; j < n; j++)
			if (x[j] < x[i])
				swap(x, i, j);
}

/**************************************************
希尔排序
插入排序的一种
n为数组x的长度。
以h为间隔进行插入排序，并不断减小h的值，直到h的值为1。
**************************************************/
void shellsort(DType x[], int n)
{	int i, j, h;
	for (h = 1; h < n; h = 3*h + 1)//至少要分成3组
		;
	for (;;) {
		h /= 3;
		if (h < 1) break;
		for (i = h; i < n; i++) {
			for (j = i; j >= h; j -= h) {
				if (x[j-h] < x[j]) break;
				swap(x, j-h, j);
			}
		}
	}
}
