#include <stdio.h>

int Merge(int r[], int r1[], int low, int mid, int high) {
	//合并R[low]~R[mid]、R[mid+1]~R[high]，结果在R1中
	int i, j, k;
	int count = 0;  //统计逆对数
	i = low; j = mid + 1; k = low; //k是r1的下标 
	while (i <= mid && j <= high)
	if (r[i] <= r[j]) r1[k++] = r[i++];  //顺序对
	else { r1[k++] = r[j++]; count += mid - i + 1; }  //取小者复制
	while (i <= mid) r1[k++] = r[i++]; //复制左子表剩余
	while (j <= high) r1[k++] = r[j++]; //复制右子表剩余
	return count;
}


int ConversedPairs(int r[], int s, int t)
{
	int m, left, right, mid;
	int r1[1000] = { 0 };
	if (s == t) return 0;      //只有一个元素，逆对为0
	else {
		m = (s + t) / 2;         //划分
		left = ConversedPairs(r, s, m);    //递归统计前半个子序列
		right = ConversedPairs(r, m + 1, t);  //递归统计后半个子序列
		mid = Merge(r, r1, s, m, t); //统计交差逆对数
		for (int i = s; i <= t; i++)
			r[i] = r1[i];
		return left + right + mid;  //返回总逆对数
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