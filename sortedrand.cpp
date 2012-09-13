#include "stdafx.h"
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int bigrand()
{	return RAND_MAX*rand() + rand();
}

int randint(int l, int u)
{	return l + bigrand() % (u-l+1);
}

/**************************************
输出从0到n中的m个随即的数。
遍历0到n并输出概率成功的值。
***************************************/
void genknuth(int m, int n)
{	for (int i = 0; i < n; i++)
		/* select m of remaining n-i */
		if ((bigrand() % (n-i)) < m) {
			cout << i << "\n";
			m--;
		}
}

/*****************************************************************
输出从0到n中的m个随即的数。
用随机函数产生随机数并对n求余，并插入集合中，直到集合的个数满足m。
*******************************************************************/
void gensets(int m, int n)
{	set<int> S;
 	set<int>::iterator i;
	while (S.size() < m) {
		int t = bigrand() % n;
		S.insert(t);//如果相同元素已经存在就不会插入。
	}
	for (i = S.begin(); i != S.end(); ++i)
		cout << *i << "\n";
}

/*****************************************************************
输出从0到n中的m个随即的数。
先把数组x初始化为0到n个数，然后把前面的m个数打乱，再排序就是结果。
*******************************************************************/
void genshuf(int m, int n)
{	int i, j;
	int *x = new int[n];
	for (i = 0; i < n; i++)
		x[i] = i;
	for (i = 0; i < m; i++) {
		j = randint(i, n-1);
		int t = x[i]; x[i] = x[j]; x[j] = t;
	}
	sort(x, x+m);
	for (i = 0; i < m; i++)
		cout << x[i] << "\n";
}

/*****************************************************************
输出从0到n中的m个随即的数。
此方法每次循环都必然会插入一个新元素。
*******************************************************************/
void genfloyd(int m, int n)
{	set<int> S;
	set<int>::iterator i;
	for (int j = n-m; j < n; j++) {
		int t = bigrand() % (j+1);
		if (S.find(t) == S.end())
			S.insert(t); // t not in S
		else
			S.insert(j); // t in S
	}
	for (i = S.begin(); i != S.end(); ++i)
		cout << *i << "\n";
}

/**********************************************************************************
题目：
如何从n个对象（可以依次看到这n个对象，但事先不知道n的值）中随机选择一个？具体说来，
如何在事先不知道文本文件行数的情况下读取该文件，从中随机选择并输出一行？
***********************************************************************************/
/*
解答：
我们总选择第1行，并以概率1/2选择第2行，以概率1/3选择第3行，依次类推。在这一过程结束时，
每一行的选中概率是相等的（都是1/n，其中n是文件的总行数）：
i = 0;
while more input lines
	with probability 1.0/++i
		choice = this input line
print choice
*/

