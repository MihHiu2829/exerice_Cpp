#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<alloc.h>
#include<process.h>
#include<math.h>
#define MAX 100



void NhapMang(int *a,int n, int m)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
        	printf("Nhap a[%d][%d]", i,j);
        	scanf("%d", (a+i*n+j));
		}
    }
}

void XuatMang(int *a, int n, int m)
{
    for(int i=0;i<m;i++)
    {
        for(int j;j<n;j++)
        {
        	printf("%4d",*(a+i*n+j));
		}
		printf("\n");
    }
}

//a. TÃ¬m tá»•ng cÃ¡c pháº§n tá»­ nguyÃªn tá»‘ cá»§a máº£ng. 
int checkSNT(int *a, int n, int m)
{
    if(n<2)
        return 0;
    for(int i=2; i<=n/2; i++)
        if(n%i==0)
            return 0;
        return 1;
}
 
void TongSNT(int *a,int n, int m)
{
    long tong=0,dem=0;
    printf("\nSo nguyen to trong mang la : \n");
    for(int i=0;i<m;i++)
    	for(int j=0;j<n;j++)
    	{
    		if(checkSNT(*(a+i*j+n)))
            {
                printf("%d\t");
                tong+=tong+*(a+i*j+n);
                dem++;
            }
		}
    if(!count)
    {
        printf("Khong co so nguyen to trong mang !\n");
    }
    else
    { 
        printf("\nTong cac SNT tren = %ld",tong);
    }
}
/* int sumSNT(int *a, int i, int m, int n)
{
	for(int i=0;i<m;i++)
    	for(int j=0;j<n;j++)
    	{
    		if (i == 0)
				{
					if (CheckSNT(*a) == 1)
					{
						return a[0];
					}
					return 0;
				}
				if (CheckSNT(a[i]) == 1)
				{
					return a[i] + sumSNT(a, i - 1);
				}
				return sumSNT(a, i - 1);
    	}
	
}
*/

// b. TÃ¬m giÃ¡ trá»‹ lá»›n nháº¥t cá»§a máº£ng.
int Maxx(int *a,int n, int m)
{
    int *max=a;
   
    for(int i=1;i<m;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		if(max[i] > *max)
            *max=max[i][j];
		}
	}    
    return *max;
}

int main()
{
    int *a;
    int m, n;
    printf("\nNhap so hang : ");
    scanf("%d",&m);
    printf("\nNhap so cot : ");
    scanf("%d",&n);
    NhapMang(a,m,n);
    XuatMang(a,m,n);
    TongSNT(a,n,m);
    Maxx(a,n,m);
    getch();
}