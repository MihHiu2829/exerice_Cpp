#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void SizeMT(int *m )
{
	do
	{
		scanf("%d", m);
		if(*m <= 0 || *m >= 200)
		{
			printf("Nhap lai: ");
		}
	}
	while(*m <= 0 || *m >= 200);

}

void NhapMaTran(int*a , int m , int n)
{
	int i;
	int j;
	for(i=0 ; i<m ; i++)
	{
		for(j=0 ; j<n ; j++)
		{
			printf("\nNhap a[%d][%d]:", i ,j);
			scanf("%d", (a+i*n+j));
		}
	}
}

void XuatMaTran(int*a , int m , int n)
{
	int i;
	int j;
	for(i=0 ; i<m ; i++)
	{
		for(j=0 ; j<n ; j++)
		{
			printf("%4d", *(a+i*n+j));

		}
		printf("\n");
	}
}

void Min(int *a, int m, int n)
{
	int min = a[0];
	int u = 0, v = 0, i, j;
	for(i = 0; i < m; i++)
	{
		for( j = 0; j < n; j++)
		{
			if(*(a + i*n + j) < min)
			{
				min = *(a + i*n + j);
				u =i;
				v=j;
			}
		}
	}
	printf("\nGia tri phan tu nho nhat Min: a[%d][%d]=%d",u,v, min);
}

void CountLe(int *a,int n, int m)
{
	int i,j;
	int dem;
	for(i = 0 ; i < n ; i++ )
	{
		dem = 0;
		for(j =0 ; j < m ; j++)
			if(*(a + i*n + j) %2 != 0)
			{
				dem++;
			}
		printf("\nSo le tren moi dong %d la %d", i , dem);
	}
}

int SumCot(int *a , int n ,int m)
{
	int i, j;
	int sum = 0;
	for(i = 0 ; i < m ; i++ )
	{
		sum=0;
		for(j =0 ; j < n ; j++)
		{
			sum += *(a +i*n+j);
		}
		printf("\nTong phan tu tren cot %d = %d ", i ,sum);
	}
}
//int SumCotRemake(int *a,int n,int m)
//{
//	int i , 
// } 
void LietKeCacDongGiamDan(int *a,int n,int m)
{
	int i, j;
	int count;
	for (i = 0; i < n; i++)
	{
		count = 0;
		for (j = 0; j < m - 1; j++)
		{
			if (*(a + i*n + j) > *(a + i*n + j+1))
			{
				count++;
			}
		}
		if(count == m - 1)
		{
			printf("\nDong %d ", i);
		}
		else
		{
			printf("\nKhong co dong co thu tu giam dan ");
		}
	}

}


int CheckSNT(int n)
{
	if(n<2)
		return 0;
	int i;
	for(i=2; i<= sqrt(n); i++)
	{
		if(n%i==0)
			return 0;
	}
	return 1;
}

int SortSNT(int *a, int m, int n)
{
	int i, x, y;
	for(i = 0 ; i < m ; i++)
	{
		int haveSwap = 0;
		for(x = 0 ; x < n-1; x++)
		{
			haveSwap = 0;
			for(y = 0 ; y < n - y - 1; y++)
			{
				if(CheckSNT(*(a+i*n+y)) == 1 && CheckSNT(*(a+i*n+y+1))==1)
				{
					if(*(a+i*n+y) > *(a+i*n+y+1))
					{
						int tmp = (*(a+i*n+y));
						(*(a+i*n+y)) = (*(a+i*n+y+1));
						(*(a+i*n+y+1)) = tmp;
						haveSwap = 1;
					}
				}
			}
			if(haveSwap == 0)
				break;
		}
	}
}
int main ()
{
	int *a, m ,n;
	printf("Nhap dong: ");
	SizeMT(&m);
	printf("Nhap cot: ");
	SizeMT(&n);
	a = (int *) malloc(m *n * sizeof(int));
	NhapMaTran(a, m, n);
	XuatMaTran(a, m, n);
	Min(a,m,n);
	CountLe(a, m ,n);
	SumCot(a,m,n);
	LietKeCacDongGiamDan(a,m,n);
	SortSNT(a,m,n);
	printf("\n Dong co thu tu giam dan la %d ", SortSNT(a,m,n));
	return 0;
}
