#include<iostream>
#include<bits/stdc++.h>
using namespace std ; 
void nhap(int *p,int row,int col)
{
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
               cout<<"a["<<i+1<<"]["<<j+1<<"]: "; 
               cin>>*(p+(i*row+j))  ; 
        }
    }
}
void xuat(int *p,int row,int col){
     for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
              cout<<*(p+(i*row+j))<<"  " ; 
        }
        cout<<endl ; 
    }
}
int Tong(int *p,int row,int col){
    int sum = 0  ; 
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            sum+=*(p+(i+row+j)) ; 
        }
    }
    return sum ;  
}
int main(){
    int row,col,*p  ;  
    cout<<"Nhap lan luot so hang va so cot cho ma tran: " ;  
    cin>>row;
    cin>>col ;    
     p =(int*) malloc(sizeof(int)* row*col) ;
    nhap(p,row,col) ; 
    xuat(p,row,col);  
    cout<<"Tong phan tu trong ma tran: "<<Tong(p,row,col) ;  
    free(p) ;     
}