#include <stdio.h>

int Merge(int r[], int r1[], int low, int mid, int high) {
	//�ϲ�R[low]~R[mid]��R[mid+1]~R[high]�������R1��
	int i, j, k;
	int count = 0;  //ͳ�������
	i = low; j = mid + 1; k = low; //k��r1���±� 
	while (i <= mid && j <= high)
	if (r[i] <= r[j]) r1[k++] = r[i++];  //˳���
	else { r1[k++] = r[j++]; count += mid - i + 1; }  //ȡС�߸���
	while (i <= mid) r1[k++] = r[i++]; //�������ӱ�ʣ��
	while (j <= high) r1[k++] = r[j++]; //�������ӱ�ʣ��
	return count;
}


int ConversedPairs(int r[], int s, int t)
{
	int m, left, right, mid;
	int r1[1000] = { 0 };
	if (s == t) return 0;      //ֻ��һ��Ԫ�أ����Ϊ0
	else {
		m = (s + t) / 2;         //����
		left = ConversedPairs(r, s, m);    //�ݹ�ͳ��ǰ���������
		right = ConversedPairs(r, m + 1, t);  //�ݹ�ͳ�ƺ���������
		mid = Merge(r, r1, s, m, t); //ͳ�ƽ��������
		for (int i = s; i <= t; i++)
			r[i] = r1[i];
		return left + right + mid;  //�����������
	}
}

void main()
{
	int n, r[1000];
	printf("Please enter the size of an array:\n");
	scanf("%d", &n);
	printf("Please enter the array:\n");
	for (int i = 0; i < n; i++)
		scanf("%d,", &r[i]);
	int count = ConversedPairs(r, 0, n - 1);
	printf("The number of oppersite pair is %d.\n", count);
}