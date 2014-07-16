/******************************************************************************
*       COPYRIGHT NOTICE
*       Copyright (c) 2014 All rights reserved
*       ----Stay Hungry Stay Foolish----
*
* @author		:Shen
* @name         :[NWPU][2014][TRN][5] I
* @file         :G:\My Source Code\��ACM��ѵ��\[NWPU][2014][TRN][5][0714]������̰��\I.cpp
* @date         :2014/07/15 17:37
* @algorithm    :Binary Search
******************************************************************************/

#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-5;
const double inf = 0xfffffff;
const double PI = acos(1.0);

double l, n, c, lp;

inline bool test(double x)
{
	double angle = asin(l / x);
	double tmplp = x * angle;
	return tmplp > lp;
}

double Bsearch(double l, double r)
{
	while (r - l > eps)
	{
		double mid = (r + l) * 0.5;
		//printf("%16.4lf%16.4lf%16.4lf\n", l, mid, r);
		if (test(mid)) l = mid;
		else r = mid;
	}
	return r;
}

void solve()
{
	if (n * c < 0.000001)
		printf("0.000\n");
	else
	{
		lp = (1.0 + n * c) * l;
		lp /= 2; l /= 2;//����������������
		double r = Bsearch(0.0, inf);
		double h = r - sqrt(r * r - l * l);
		//G++
		printf("%.3f\n", h);
		//C++
		//  printf("%.2lf\n", h);
	}
}

int main()
{
	while (~scanf("%lf%lf%lf", &l, &n, &c))
		if (l < 0) break;
		else solve();
		return 0;
}