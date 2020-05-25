#include <stdio.h>

void main()
{
	int A, B, C, D, E, F;
	printf("The criminals are:\n");
	for (A = 0; A <= 1; A++)  		//穷举A的情况
	for (B = 0; B <= 1; B++) 		//穷举B的情况
	for (C = 0; C <= 1; C++) 		//穷举C的情况
	for (D = 0; D <= 1; D++) 	//穷举D的情况
	for (E = 0; E <= 1; E++) 	//穷举E的情况
	for (F = 0; F <= 1; F++) 	//穷举F的情况
	{
		//对每种方案检验是否符合下面6个条件，不符合则检验下一个方案
		if (A == 0 && B == 0) continue;
		if ((A == 0 && E == 0) || (A == 0 && F == 0) || (E == 0 && F == 0)) continue;
		if (A == 1 && D == 1) continue;
		if ((B == 1 && C == 0) || (B == 0 && C == 1)) continue;
		if ((C == 0 && D == 0) || (C == 1 && D == 1)) continue;
		if (D == 0 && E == 1) continue;
		//输出合法方案
		if (A == 1) putchar('A');	if (B == 1) putchar('B');
		if (C == 1) putchar('C');	if (D == 1) putchar('D');
		if (E == 1) putchar('E');	if (F == 1) putchar('F');
		putchar('\n');
	}
}
