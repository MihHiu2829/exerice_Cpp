#include<iostream>
#include<math.h>
using namespace std ;  
void nhap(int a[],int n)
{    
    cout<<"Nhap phan tu thu 1: " ; 
    cin>>a[0] ;  
        for(int i=1;i<n;i++)
        {        
            here: 
              cout<<"Nhap vao phan tu thu "<<(i+1)<<endl ;  
              cin>>a[i] ;  
              for(int j=0;j<i;j++)
              {
                  if(a[i] == a[j]) {
                        cout<<"co phan tu trung, vui long nhap lai: " ; 
                        goto here ; 
                  }
              }
        }
}
bool so9phuong(int a){
    if(a<1)
        return false;
    int i=1;
    while(i*i<=a){
        if(i*i==a)
            return true;
        i++;
        }
    return false;
}
void xuat(int a[],int n)
{    
       cout<<"Cac phan tu trong mang: " ; 
      for(int i=0;i<n;i++)
      {
          cout<<a[i]<<"\t"; 
      }
}
void so9phuong_le(int a[],int n){
     for(int i=0;i<n;i++)
     {
         if(so9phuong(a[i]) && a[i] % 2 == 1 ) 
             cout<<a[i]<<"\t" ;  
     }
}
int Max(int array[],int size){
    int max = array[0]; 
    for(int i=1;i<size;i++){
          if(array[i] > max ) max = array[i] ; 
    }
    return max; 
}
void xuatSoLonNhat(int a[],int n)
{
    int max = Max(a,n) ; 
     for(int i=0;i<n;i++)
     {
         if(a[i] == max) cout<<i+1<<"\t";  
     }
}
int tongChan(int a[],int n)
{
     int sum = 0 ;  
     for(int i=0;i<n;i++)
     {
         if(a[i]%2 == 0) sum+=a[i] ; 
     }
     return sum ;  
}
void sortincread(int a[],int n)
{
        int j,i,key  ; 
        for(int i=1;i<n;i++)
        {
            key = a[i] ;  
            j = i - 1 ; 
             while(j >= 0  && a[j] > key )
             {
                 a[j+1] = a[j] ;  
                 j-- ; 
                
             } a[j+1]  = key ;
        }
}
int main(){
    int n ;  
    cout<<"Nhap vao so luong phan tu trong mang" ;  
    cin>> n ;  
    int a[100] ;  
    nhap(a,n) ; 
    sortincread(a,n) ; 
    xuat(a,n) ; 
}