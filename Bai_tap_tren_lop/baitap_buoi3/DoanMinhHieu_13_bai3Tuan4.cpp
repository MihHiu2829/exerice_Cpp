#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct ps
{
	int tu;
	int mau;
};
void NhapN(int &n)
{
	printf("Nhap n = ");
	scanf("%d",&n);
}
void NhapPhanSo(ps *a, int n )
{
	for(int i=0; i<n; i++){
		printf("a[%d]\n", i);
		printf("Nhap tu: ");	scanf("%d", &(a+i)->tu);
		do{
			printf("Nhap mau: ");	scanf("%d", &(a+i)->mau);
		}while(a->mau==0);
	}
}
void XuatPS(ps a)
{
	printf("%d/%d", a.tu, a.mau);
}
void XuatPhanSo(ps *a, int n){
	for(int i=0; i<n; i++){
		printf("%d/%d ", (a+i)->tu, (a+i)->mau);
	}
}



int UocChungLonNhat(int a, int b)
{
	while(a!=0 && b!=0)
		if(a>b) a-=b;
		else b-=a;
	return a;
}
ps RutGon(ps &a)
{
	int uc = UocChungLonNhat( abs(a.tu) , abs(a.mau) );
	a.tu/=uc;
	a.mau/=uc;
	return a;
}
int SoSanh(ps a, ps b)
{
	int left = a.tu*b.mau;
	int right = a.mau*b.tu;
	if(left>right) return 1;
	if(left<right) return -1;
	return 0;
}
int TimPSMax(ps *a, int n)
{
	int vt = 0;					
	for(int i=1; i<n; i++)		
		if(SoSanh(*(a+i), *(a+vt)) > 0)		
			vt=i;						
	return vt;				
}	
ps Tong(ps a, ps b)
{
	ps kq = {0,1};
	kq.tu = a.tu*b.mau + a.mau*b.tu;
	kq.mau= a.mau*b.mau;
	return RutGon(kq);
}
ps TongMang(ps *a, int n)
{
	ps kq = {0,1};
	for(int i=0; i<n; i++)
		kq = Tong(kq,*(a+i));
	return kq;
}
int main()
{
	int n;
	ps *p;
	NhapN(n);
	p=(ps*)malloc(n*sizeof(int));
	NhapPhanSo(p, n);
	printf("Phan so vua nhap: ");
	XuatPhanSo(p, n);
	int max=TimPSMax(p, n);
	printf("\nPhan so lon nhat tai a[%d]", max);
	ps kq = TongMang(p, n);
	printf("\nKet qua tong mang = "); XuatPS(kq);
	free(p);
	return 0;
}
