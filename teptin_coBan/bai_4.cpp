#include<bits/stdc++.h>
using namespace std ; 
typedef struct monHang{
    string maHang ; 
    int sl   ;
    float dongia ;  
    float soTien ;  

}mH;
void nhap(mH *p,int n){
    for(int i=0;i<n;i++)
    {
        cout<<"Nhap mat hang thu "<<i+1<<endl ;  
         cout<<"Nhap ma hang: " ;  
         fflush(stdin); 
         getline(cin,p[i].maHang) ;  
         cout<<"So luong mon hang: "; 
         cin>>p[i].sl ;  
         cout<<"Nhap gia cua mon hang: "; 
         cin>>p[i].dongia ; 
         p[i].soTien = p[i].sl * p[i].dongia ;  
    }
}
void xuat(mH *&p,int n){
    FILE *file = fopen("bai_4.inp","w") ; 
    fprintf(file,"%-10s %-20s %-20s %-20s %-20s\n","So thu tu","Ma hang","So luong","Don gia","Tong tien"); 
     for(int i=0;i<n;i++){
        fprintf(file,"%-10d %-20s %-20d %-20f %-20f\n",(i+1),p[i].maHang.c_str(),p[i].sl,p[i].dongia,p[i].soTien); 
     }
}
int main(){
     int n  ; 
     cout<<"Nhap so luong mon hang can nhap vao : "; 
     cin>>n  ; 
     mH *p = new mH[n] ;  
     nhap(p,n) ;  
     xuat(p,n) ;  
}