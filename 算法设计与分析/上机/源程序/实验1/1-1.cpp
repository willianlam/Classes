#include <stdio.h>

void main()
{
	int A, B, C, D, E, F;
	printf("The criminals are:\n");
	for (A = 0; A <= 1; A++)  		//���A�����
	for (B = 0; B <= 1; B++) 		//���B�����
	for (C = 0; C <= 1; C++) 		//���C�����
	for (D = 0; D <= 1; D++) 	//���D�����
	for (E = 0; E <= 1; E++) 	//���E�����
	for (F = 0; F <= 1; F++) 	//���F�����
	{
		//��ÿ�ַ��������Ƿ��������6���������������������һ������
		if (A == 0 && B == 0) continue;
		if ((A == 0 && E == 0) || (A == 0 && F == 0) || (E == 0 && F == 0)) continue;
		if (A == 1 && D == 1) continue;
		if ((B == 1 && C == 0) || (B == 0 && C == 1)) continue;
		if ((C == 0 && D == 0) || (C == 1 && D == 1)) continue;
		if (D == 0 && E == 1) continue;
		//����Ϸ�����
		if (A == 1) putchar('A');	if (B == 1) putchar('B');
		if (C == 1) putchar('C');	if (D == 1) putchar('D');
		if (E == 1) putchar('E');	if (F == 1) putchar('F');
		putchar('\n');
	}
}
