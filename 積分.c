#include  <stdio.h>
# include <math.h>

int main()
{
	double n = 0.0, sum = 0.0, i, b, c, e = 0.0;
	printf("请输入函数下限\n");
	scanf_s("%lf", &n);
	printf("请输入函数上限\n");
	scanf_s("%lf", &e);
	b = e / 1000000.000;                 //分母为精度
	c = 1.000 / b;
	for (i = 0; i < 1000000; i++)
	{
		n += b;
		sum += sin(n);              //函数表达式，需后台输入
	}
	printf("%3f", sum / c);
}
