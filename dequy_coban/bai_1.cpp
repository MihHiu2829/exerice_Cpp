#include<iostream>
using namespace std ;  
void input(int a[],int n){
    if (n == 0 ) return ;  
    input(a,n-1) ;  
    cout<<"Nhap phan tu thu "<<n<<": " ; 
    cin>>a[n-1] ;  
}
void output(int a[],int n){
    if(n== 0) return ;  
    output(a,n-1) ;  
    cout<<a[n-1]<<" " ;  
}
int sum(int a[],int n){
    if(n==0) return 0 ;  
    return a[n-1] + sum(a,n-1) ;  
}
int demDuong(int a[],int n){
    if(n==0 ) return  0  ; 
    if(a[n-1] > 0 ) return demDuong(a,n-1) + 1 ;  
    else return demDuong(a,n-1) ;  
}
int Max(int a[], int n)
{
	if (n == 0)
		return -1;
	if (n == 1)
		return a[0];
	else
	{
		if (a[n - 1] > Max(a, n - 1))
			return a[n - 1];
		else
			return Max(a, n - 1);
	}
}
int even(int a[],int n){
    if(n == 0 ) return -1 ;  
    if (a[n-1] % 2 == 0 ) return a[n-1]  ; 
    else  return even(a,n-1) ;  
}
int find(int a[],int n,int x){
    if(n == 0 ) return -1   ;
    if(a[n-1] == x ) return n-1 ;  
    else return find(a,n-1,x) ;  
}
int  main(){
    int  n  ;
    cout<<"Nhap n:" ;  
    cin>>n  ; 
    int a[100]   ;  
    input(a,n) ;   
    output(a,n) ;  
    cout<<"tong cac phan tu la: "<<sum(a,n)<<endl  ; 
    cout<<"So phan tu duong la: "<<demDuong(a,n) <<endl ;  
    cout<<"So lon nhat la: "<<Max(a,n) <<endl ; 
    cout<<"So chan cuoi cung la:"<<even(a,n) <<endl ;  
    cout<<"Nhap vao gia tri x :"; 
    int x  ;
    cin>>x ;
    cout<<"Vi tri x xuat hien cuoi cung trong mang la: "<<find(a,n,x) ;   
}