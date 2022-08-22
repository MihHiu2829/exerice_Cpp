#include<iostream>
using namespace std ;  
int indexMax(int a[],int n){  // =========================== cau g 
	int max = a[0]  ; 
	int index = -1 ;  
	for(int i=1;i<n;i++){
		if(a[i] > max ) {
		max = a[i] ;
		index = i ;  	
		}  
	}
	return index ; 
}
void themvaodaumang(int a[],int &n){
	int tmp =0 ;  
	cout<<"Nhap so nguyen ban thich: "  ; 
	cin>>tmp ;  
	for(int i=n;i>0;i--){
		a[i]  = a[i-1] ;  
	}
	a[0] = tmp ;  
	n++ ; 
}
void output(int a[],int n){
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<"  " ;  
	}
}
void input(int a[],int n){  // ========================== cau h 
	for(int i=0;i<n;i++){
		cout<<"Nhap phan tu thu "<<i+1<<" :"; 
		cin>>a[i] ;  
	}
}
void delete_phantu(int a[],int k,int &n){ // =========================== cau K
	if(k >= n || k < 0 ) {
		cout<<"vi tri khong ton tai! "<<endl ;  
	}
	for(int i=k+1;i<n;i++){
		a[i-1] = a[i] ;  
	}
	n-- ; 
}
bool check(int a[],int n){  // =========================== Cau l
	for(int i=0;i<n;i++){
		  if(a[i] % 2 == 1) return 1 ; 
	}
	return 0 ;  
}
int main(){
	int n ;  
	cout<<"Nhap so luong phan tu cua mang: "; 
	cin>>n ;  
	int a[100];  
	input(a,n) ;
	cout<<"Phan tu lon nhat co vi tri: "<<indexMax(a,n)<<endl  ;  
	themvaodaumang(a,n) ;  // cau h 
	output(a,n) ;  
	cout<<endl ; 
	int k  ; 
	 cout<<"Nhap k: " ; 
	 cin>>k ;  
	delete_phantu(a,k,n) ;  // cau k  ;  
	output(a,n) ; 
	cout<<endl ;  
	if(check(a,n)) cout<<"Mang co phan tu le"<<endl  ;
	else cout<<"Mang khong co phan tu le"<<endl ;  
	}
