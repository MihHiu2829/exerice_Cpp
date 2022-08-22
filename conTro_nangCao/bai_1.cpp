#include<bits/stdc++.h>
using namespace std ; 
typedef struct phanso{
       int mauso , tuso ;  
}ps; 
void nhap1ps(phanso *p){
    cout<<"Nhap tu so: "; 
    cin>>p->tuso ;  
    cout<<"Nhap mau so: " ; 
    cin>>p->mauso;  
}
void nhapNhungPhanSo(phanso *p,int n){
        
    for(int i=0;i<n;i++){
        cout<<"Nhap phan so thu "<<i+1<<": " ;  
        nhap1ps(p+i) ; 
    }
}
void xuat1phanso(ps *p){
    cout<<p->tuso<<"/"<<p->mauso<<endl; 
}
void xuatnhungphanso(phanso *p,int n){
    for(int i=0;i<n;i++){
        cout<<"Phan so thu: "<<i+1<<" ";
		xuat1phanso((p+i)) ; 
    }
}
float soChia(ps *p){ 
     if(p->mauso == 0 ) return 0 ; 
     float a =  p->tuso ;  
     float b = p->mauso ;  
     float tmp = (a/b) ;  
    return tmp  ;  
}
void timMax(ps *p,int n){
    float max =  soChia(p+0)  ; 
    int local =  0 ;    
    for(int i=1;i<n;i++){
          if(max < soChia(p+i)) {
              max = soChia(p+i) ;  
              local =  i  ;  
          }
    }
    cout<<"Phan so lon nhat la: "<<endl ; 
    xuat1phanso(p+local) ;  
}
double tong(ps *p,int n){
    float sum = 0  ;
    for(int i=0;i<n;i++){
         sum+=soChia(p+i) ;  
    }
    return sum ;  
}
int main(){
      int n  ; 
       cout<<"Nhap vao so luong phan so: ";  
       cin>>n ; 
            ps *p ; 
//            nhap1ps(p) ;  
//            xuat1phanso(p);  
        p = new ps[n] ;  
        nhapNhungPhanSo(p,n) ; 
     xuatnhungphanso(p,n) ;   
     timMax(p,n) ;  
      cout<<"Tong cac phan so la:"<<tong(p,n); 
       delete(p) ;  
}
