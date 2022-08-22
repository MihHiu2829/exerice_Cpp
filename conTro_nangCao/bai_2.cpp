// #include<bits/stdc++.h>
#include<iostream>
#include<string> 
using namespace std ;  
typedef struct sinhvien{
         string hoTen, maSo, date,lop ; 
         bool sex  ; 
         float toan,li,tin ;  
}sv;  
void nhap1sv(sv *p){
    cout<<"Ho va ten sinh vien: "; 
    fflush(stdin) ; 
    getline(cin,p->hoTen) ;
    cout<<"Ma so sinh vien: " ; 
    getline(cin,p->maSo)  ;  
    cout<<"Ngay thang nam sinh (XX/XX/XXXX):";
    getline(cin,p->date) ;   
    cout<<"Lop hoc: "; 
    getline(cin,p->lop) ;  
    cout<<"Gioi tinh (1: nam/0: nu): "; 
    int sellect ; 
    cin>>sellect; 
    if(sellect == 0 ) p->sex = false ;  
    else p->sex = true ;  
    cout<<"nhap diem toan cua sinh vien "<<p->hoTen<<" : "; 
    cin>>p->toan ;  
    cout<<"nhap diem li cua sinh vien "<<p->hoTen<<" : "; 
    cin>>p->li ;  
    cout<<"nhap diem tin cua sinh vien "<<p->hoTen<<" : "; 
    cin>>p->tin ;  
}
void nhapnhungsinhvien(sv *p,int n){
    for(int i=0;i<n;i++){
        cout<<"Sinh vien "<<i+1<<endl ;  
        nhap1sv(p+i) ;  
    }
}
void xuat1sv(sv *p){
    printf("%-20s %-15s %-15s %-15s %-10d %-10f %-10f %-10f\n",p->hoTen.c_str(),p->maSo.c_str(),p->date.c_str(),p->lop.c_str(),p->sex,p->toan,p->li,p->tin) ;  

}
void xuatnhungsv(sv *p,int n){
    cout<<"Thong tin nhung sinh vien"<<endl ;  
    printf("%-20s %-15s %-15s %-15s %-10s %-10s %-10s %-10s\n","Ho va ten","Ma sinh vien","Ngay sinh","Lop hoc","gioi tinh","toan","li","tin") ;  
    for(int i=0;i<n;i++){
        xuat1sv(p+i);
    }
}
void xuatSvcomaSinhViennhaptubanphim(sv *p,int n)
{
    cout<<"Nhap ma sinh vien muon tim kiem: ";
    int flag = 1  ; string msv ;  
    fflush(stdin) ;  
    getline(cin,msv);
    printf("%-20s %-15s %-15s %-15s %-10s %-10s %-10s %-10s\n","Ho va ten","Ma sinh vien","Ngay sinh","Lop hoc","gioi tinh","toan","li","tin") ;  
    for(int i=0;i<n;i++){
        if(((p+i)->maSo).compare(msv)== 0) {
            xuat1sv(p+i) ;  
            flag = 0 ;  
        }
    }
    if(flag) cout<<"Khong co thong tin ve ma sinh vien ban nhap."<<endl ; 
}
// con 1 vai cau xam lonz qua ko muon lam. neu bai nay co thi hay hoi co cu the 1 ti
int main(){
    int n  ; 
    cout<<"Nhap so luong sinh vien: " ; 
    cin>>n ;  
    sv *p   = new sv[n] ;  
    nhapnhungsinhvien(p,n) ;  
    xuatnhungsv(p,n);
    xuatSvcomaSinhViennhaptubanphim(p,n);
}