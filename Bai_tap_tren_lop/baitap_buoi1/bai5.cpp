#include<iostream>
#include<math.h>
using namespace std  ; 
void nhap(int a[],int n){
	for(int i=0;i<n;i++){
		cout<<"Nhap phan tu thu "<<i+1<<" : " ;  
	cin>>a[i] ;  
	}  
}
int checkPrime(int n){
	if( n < 2 ) return  0  ;  
	for(int i=2 ; i<=sqrt(n) ; i++){
		     if (n % i == 0) return  0 ;  
	}
	return 1;  
}
int CountPrime(int a[],int n){
	int dem = 0  ;  
	for(int i=0;i<n;i++){
		if(checkPrime(a[i])) dem++ ; 
	}
	return dem ;  
}
int main(){
     int n ;  
     cout<<"Nhap so luong phan tu trong mang: " ;  
     cin>>n ;  
     int a[n] ;   
     nhap(a,n) ; 
     cout<<"so luong so nguyen to trong mang a la: "<<CountPrime(a,n)<<endl ; 
     int b[] = {7,3,12,45,90,23} ; 
     cout<<"So luong so nguyen to trong mang b la: "<<CountPrime(b,sizeof(b)/sizeof(b[0])); 
}
