#include<iostream>
#include<algorithm>
using namespace std ;
void sort_select(int a[],int n){
   int j,key  ; 
   for(int i=1;i<n;i++){
     key = a[i]  ; 
       j = i - 1   ; 
       while(j>=0 and a[i] > key){
           a[j+1] = a[j] ;  
           j-- ; 
       }
       a[j+1]  =  key  ;  
   }
}
void bubble_sort(int a[],int n){
   for(int i=0;i< n ;i++){
       for(int j=n-1;j>1;j--){
           if(a[j] < a[j-1]) swap(a[j],a[j-1]);
       }
   }
}
void interchange_sort(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
                if(a[i] > a[j]) 
                    swap(a[i],a[j]) ;  
        }
    }
}
void Input(int a[],int n){
    for(int i=0;i<n;i++){
        a[i]  =  rand() % 100 ;  
    }
}
void Output(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" "  ; 
    }
}
int main(){
      int n  ;  
      cout<<"Nhap vao n: "  ; 
      cin>>n ;   
      int a[100] ;  
     Input(a,n) ; 
    interchange_sort(a,n) ;   
     Output(a,n);
}