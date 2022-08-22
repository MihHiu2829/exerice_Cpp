#include<bits/stdc++.h>
using namespace std ;  

//================================================= Cau a  
void nhapMang(int A[], int n,int  i = 0){
    if(i == n) 
        return   ;
    printf("Nhap phan tu thu A[%d] = ", i);
    scanf("%d", &A[i]);
    nhapMang(A,n,i+1);
}
// ================================================ Cau b 
void xuatMang(int A[], int n,int i = 0 ){  
    if(i == n)
        return; 
    printf("%5d", A[i]); 
    xuatMang(A, n, i+1);
}
// ================================================ Cau c 
int tinhTong(int A[],int n,int i = 0){
		if(i== n) 
		 return 0 ; 
		return   A[i]  +  tinhTong(A,n,i+1)  ; 
} 
// ================================================ Cau d 
int tinhTongLe(int A[],int n, int i = 0 ) {
	if (i == n )
	      return  0   ;  
	return  A[i]%2 == 1 ? A[i] + tinhTongLe(A,n,i+1) : tinhTongLe(A,n,i+1) ;   
}
//================================================= Cau c 
int timPhanTuLonNhat(int A[],int n,int i = 1,int max = -2147483646 ){
   				if (n == i ) return max ; 
   				return A[i] > max ? timPhanTuLonNhat(A,n,i+1,A[i]) : timPhanTuLonNhat(A,n,i+1,max) ;  		
 		
} 
//================================================== Cau d
int demPhanTULe(int A[],int n,int i = 0)
{
	if (n==i) return 0  ;  
	return A[i] % 2 == 1 ? 1 + demPhanTULe(A,n,i+1)  : 	demPhanTULe(A,n,i+1) ;
}
// ================================================= Cau e ;
int phantuChanCuoiCung(int A[],int n ){
	if( n < 0 ) return -1 ;  
	return A[n] % 2 == 0 ? A[n] : phantuChanCuoiCung(A,n-1) ; 
}
// ================================================= Cau f  ;  
int demPhanTuLonNhat(int A[],int n,int max,int i = 0 )
{
	if ( i == n  ) return 0  ; 
	return max == A[i] ? 1 + demPhanTuLonNhat(A,n,max,i+1) : demPhanTuLonNhat(A,n,max,i+1) ;
}
//int isPrime(int n){
//     if(n<2) return 0 ;  
//     for(int i = 2 ; i <= sqrt(n);i++)
//	 	{
//	 		if(n%i == 0 ) return 0 ; 
//		  } 
//		  return  1 ;  
//}
//int tinhTongSNT(int A[],int n,int i=0){
//	  if(i==n ) 
//	  return 0 ; 
//	 return isPrime(A[i]) == 1  ? A[i]  + tinhTongSNT(A,n,i+1)  : tinhTongSNT(A,n,i+1) ;  
//}
//int findEvenElement(int A[],int n , int i = 0){
//	if (i == n) 
//	return -1 ;  
//	return A[i] % 2 == 0 ? A[i] : findEvenElement(A,n,i+1) ;  
//}
//int GCD(int a,int b){
//	if (a == b ) return a ;  
//	return a > b ? GCD(a-b,b) : GCD(a,b-a)  ;  
//} 
int main(){
	int A[100] , n = 8 ;
//   int a = 12 , b = 4  ;  
//   cout<<"Uoc chung lon nhat: "<<GCD(a,b) ;  
   nhapMang(A,n) ; 
   xuatMang(A,n) ; 
   cout<<endl<<"Phan tu lon nhat: "<<timPhanTuLonNhat(A , n ) ;
   cout<<endl<< "so luong phan tu le trong mang : "<<demPhanTULe(A,n) ;   
   cout<<endl<<"Phan tu chan cuoi cung trong mang: "<<phantuChanCuoiCung(A,n-1) ; 
   cout<<endl<<"so luong phan tu lon nhat trong mang: "<<demPhanTuLonNhat(A,n,timPhanTuLonNhat(A,n)) ; 
}
