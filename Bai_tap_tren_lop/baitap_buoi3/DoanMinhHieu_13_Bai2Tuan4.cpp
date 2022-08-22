#include<stdio.h>
#include<stdlib.h>

void NhapMaTran(int *a, int m,int n){
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++){
			printf("a[%d][%d] = ", i, j);
			scanf("%d", (a+i*n+j));
		}
}
void XuatMaTran(int *a, int m, int n){
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			printf("%3d", *(a+i*n+j));
		}
		printf("\n");
	}
}
//////////////////Cau s/////////////////////
void vtMaxdau(int *a, int m, int n)
{
	int max=*a;
	int maxi=0;
	int maxj=0;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(max<*(a+i*n+j)){
				max=*(a+i*n+j);
				maxi=i;
				maxj=j;
			}
		}
	}
	printf("Phan tu lon nhat %d nam tai vi tri a[%d][%d]", max, maxi, maxj);
}
///////////////////////////Cau t//////////////////
int tongdong(int *a, int m, int n)
{
	int s=0;
	for(int j=0;j<n;j++)
		s=s+*(a+m*n+j);
	return s;
}
///////////////////////////cau u//////////////////////
int tonglonnhat(int *a, int m, int n)
{
	int d;
	int max=tongdong(a,0,n);
	for(int i=1; i<m; i++){
		int t=tongdong(a,i,n);
		if(max<t)
		{
			max=t;
			d=i;
		}
	}
	return d;
}
///////////////////////cau v///////////////////////////
void SapTangDan(int *a, int m, int n)
{
	int k=m*n;
	for(int i=0; i<k-1; i++){
		for(int j=i+1; j<k; j++){
			if(*(a+(i/n)*n+(i%n))>*(a+(j/n)*n+(j%n))){
				int t=*(a+(i/n)*n+(i%n));
				*(a+(i/n)*n+(i%n))=*(a+(j/n)*n+(j%n));
				*(a+(j/n)*n+(j%n))=t;
			}
		}
	}
}
int main()
{
	int m, n;
	int *p;
	printf("Nhap so dong: ");
	scanf("%d", &m);
	printf("Nhap so cot: ");
	scanf("%d", &n);
	p=(int*)malloc(m*n*sizeof(int));
	NhapMaTran(p, m, n);
	XuatMaTran(p, m, n);
	vtMaxdau(p, m, n);
	int x;
	printf("\nNhap dong can tinh tong: ");
	scanf("%d", &x);
	int s=tongdong(p, x, n);
	printf("Tong tren %d = %d", x, s);
	int dong=tonglonnhat(p, m, n);
	printf("\nDong co tong lon nhat: %d\n", dong);
	SapTangDan(p, m, n);
	XuatMaTran(p, m, n);
	free(p);
	return 0;
}
