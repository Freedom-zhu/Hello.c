#define _CRT_SECURE_NO_WARNINGS
//输入年份和月份打印该月有多少天
//需要注意闰年的二月份为29天
#include<stdio.h>
int main()
{
	int y = 0;
	int m = 0;
	int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	while (scanf("%d %d", &y, &m) != EOF)
	{
		int day = days[m];
		if (m == 2)
			if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
				day += 1;
		printf("%d\n", day);
	}
	return 0;
}