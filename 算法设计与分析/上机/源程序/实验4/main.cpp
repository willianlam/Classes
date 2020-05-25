#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int MinimalPath(int **A, int m, int n, int **path)
{
	int **d=(int **)malloc(sizeof(int)*m*n);
	for (int i = 0; i < m; i++)
		d[i] = (int *)malloc(sizeof(int)*n);

	for (int i = 0; i<m; i++)			//初始化d[i][j]
	for (int j = 0; j<n; j++)
		d[i][j] = MAX;
	d[0][0] = A[0][0];			//初始化d[0][0]
	path[0][0] = -1;
	for (int j = 1; j < n; j++)
	{
		d[0][j] = d[0][j - 1] + A[0][j];	//计算d矩阵第一行元素
		path[0][j] = 0;	//从左边过来
	}
	for (int i = 1; i < m; i++)
	{
		d[i][0] = d[i - 1][0] + A[i][0];	//计算d矩阵第一列元素
		path[i][0] = 1;	//从上边过来
	}
	for (int i = 1; i<m; i++)							//计算d[i][j]
	for (int j = 1; j < n; j++)
	{
		if (d[i - 1][j] >= d[i][j - 1])
		{
			d[i][j] = d[i][j - 1] + A[i][j];
			path[i][j] = 0; 
		}
		else
		{
			d[i][j] = d[i - 1][j] + A[i][j];
			path[i][j] = 1;
		}
	}
	return d[m - 1][n - 1];		//返回最小和
}

void FindPath(int **path, int m, int n, int *p, int **A)
{
	int i = m - 1, j = n - 1, k = m + n - 1;
	p[--k] = A[i][j];
	int t = path[i][j];
	while (t != -1)
	{
		if (t == 0) j--;
		if (t == 1) i--;
		p[--k] = A[i][j];
		t = path[i][j];
	}
}

void main()
{
	int **A,m,n;
	scanf("%d,%d", &m, &n);
	A = (int **)malloc(sizeof(int)*m*n);
	for (int i = 0; i < m; i++)
		A[i] = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i < m;i++)
	for (int j = 0; j < n; j++)
		scanf("%d", &A[i][j]);
	int **path = (int**)malloc(sizeof(int)*m*n);
	for (int i = 0; i < m;i++)
		path[i] = (int *)malloc(sizeof(int)*n);
	int minSum = MinimalPath(A, m, n, path);
	int *p = (int *)malloc(sizeof(int)*(m+n-1));
	FindPath(path, m, n, p, A);
	printf("\n");
	for (int i = 0; i < m + n - 2; i++)
		printf("%d->", p[i]);
	printf("%d\n", p[m + n - 2]);
	printf("%d\n", minSum);
}