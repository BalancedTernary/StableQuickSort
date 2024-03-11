#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
// NNtest.cpp: 定义控制台应用程序的入口点。
//

#include "StableQuickSort.h"

#define LEN 10000000

class Tt
{
public:
	double v;
	long n;
	Tt(double v, long n)
	{
		this->v = v;
		this->n = n;
	}
	Tt()
	{
		this->v = 0;
		this->n = 0;
	}
	bool operator<(const Tt& a)
	{
		return this->v < a.v;
	}
	bool operator>(const Tt& a)
	{
		return this->v > a.v;
	}
	bool operator==(const Tt& a)
	{
		return this->v == a.v;
	}
};

bool nonmem_cmp(const Tt& t1, const Tt& t2)
{
	return t1.v > t2.v;
}



int main()
{
	std::vector<Tt> tt;
	clock_t startTime;
	tt.clear();
	for (int i = 0; i < LEN; i++)
	{
		tt.push_back(Tt(rand() % 10, i));
	}

	startTime = clock();
	std::stable_sort(tt.begin(), tt.end(), nonmem_cmp);
	std::cout << "STL乱序稳定排序时间: " << 1000 * (clock() - startTime) / (double)CLOCKS_PER_SEC << "ms" << std::endl;


	startTime = clock();
	std::stable_sort(tt.begin(), tt.end(), nonmem_cmp);
	std::cout << "STL顺序稳定排序时间: " << 1000 * (clock() - startTime) / (double)CLOCKS_PER_SEC << "ms" << std::endl;

	std::reverse(tt.begin(), tt.end());
	startTime = clock();
	std::stable_sort(tt.begin(), tt.end(), nonmem_cmp);
	std::cout << "STL反序稳定排序时间: " << 1000 * (clock() - startTime) / (double)CLOCKS_PER_SEC << "ms" << std::endl;

	tt.clear();
	for (int i = 0; i < LEN; i++)
	{
		tt.push_back(Tt(0, i));
	}

	startTime = clock();
	std::stable_sort(tt.begin(), tt.end(), nonmem_cmp);
	std::cout << "STL全零稳定排序时间: " << 1000 * (clock() - startTime) / (double)CLOCKS_PER_SEC << "ms" << std::endl;
	std::cout << std::endl;

	tt.clear();
	for (int i = 0; i < LEN; i++)
	{
		tt.push_back(Tt(rand() % 10, i));
	}

	startTime = clock();
	sqs::sort(tt);
	std::cout << "SQS乱序稳定排序时间: " << 1000 * (clock() - startTime) / (double)CLOCKS_PER_SEC << "ms" << std::endl;

	startTime = clock();
	sqs::sort(tt);
	std::cout << "SQS顺序稳定排序时间: " << 1000 * (clock() - startTime) / (double)CLOCKS_PER_SEC << "ms" << std::endl;

	std::reverse(tt.begin(), tt.end());
	startTime = clock();
	sqs::sort(tt);
	std::cout << "SQS反序稳定排序时间: " << 1000 * (clock() - startTime) / (double)CLOCKS_PER_SEC << "ms" << std::endl;

	tt.clear();
	for (int i = 0; i < LEN; i++)
	{
		tt.push_back(Tt(0, i));
	}

	startTime = clock();
	sqs::sort(tt);
	std::cout << "SQS全零稳定排序时间: " << 1000 * (clock() - startTime) / (double)CLOCKS_PER_SEC << "ms" << std::endl;
	std::cout << std::endl;


	tt.clear();
	for (int i = 0; i < LEN; i++)
	{
		tt.push_back(Tt(rand() % 10, i));
	}

	startTime = clock();
	std::sort(tt.begin(), tt.end(), nonmem_cmp);
	std::cout << "STL乱序不稳定排序时间: " << 1000 * (clock() - startTime) / (double)CLOCKS_PER_SEC << "ms" << std::endl;

	startTime = clock();
	std::sort(tt.begin(), tt.end(), nonmem_cmp);
	std::cout << "STL顺序不稳定排序时间: " << 1000 * (clock() - startTime) / (double)CLOCKS_PER_SEC << "ms" << std::endl;

	std::reverse(tt.begin(), tt.end());
	startTime = clock();
	std::sort(tt.begin(), tt.end(), nonmem_cmp);
	std::cout << "STL反序不稳定排序时间: " << 1000 * (clock() - startTime) / (double)CLOCKS_PER_SEC << "ms" << std::endl;

	tt.clear();
	for (int i = 0; i < LEN; i++)
	{
		tt.push_back(Tt(0, i));
	}
	startTime = clock();
	std::sort(tt.begin(), tt.end(), nonmem_cmp);
	std::cout << "STL全零不稳定排序时间: " << 1000 * (clock() - startTime) / (double)CLOCKS_PER_SEC << "ms" << std::endl;
	std::cout << std::endl;


	system("pause");

	return 0;
}

