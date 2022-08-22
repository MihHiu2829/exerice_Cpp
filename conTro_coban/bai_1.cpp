// #include<bits/stdc++.h>
#include<iostream>
using namespace std ; 
void nhap(int *p,int n){
    for(int i=0;i<n;i++)
	{
		cout<<"a["<<i+1<<"]: "; 
		cin>>*(p+i) ; 
	}
}
void xuat(int *p,int n){
	for(int i=0;i<n;i++)
	{
		cout<<*(p+i)<<"\t" ; 
	}
}
int tong(int *p,int n){
	int sum = 0  ;
	for(int i=0;i<n;i++)
	{
		 sum+=*(p+i) ;  
	}
	return sum ; 
}
int main(){
     int n   ; 
	 cout<<"Nhap vao so luong phan tu trong mang: "; 
	 cin>>n ;  
	 int *p = new int[n] ;  
	 nhap(p,n) ;  
	 xuat(p,n) ;
	 cout<<endl; 
	 cout<<"Tong phan tu cua mang la: "<<tong(p,n) ; 
}