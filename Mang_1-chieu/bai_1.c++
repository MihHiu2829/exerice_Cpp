#include<iostream> 
using namespace std ; 
void nhap(int array[],int size){
    for(int i=0;i<size;i++){
        cout<<"Nhap vao phan tu thu "<<(i+1)<<": " ;  
        cin>>array[i]; 
    }
}
void xuat(int array[],int size){
    cout<<"mang gom: " ; 
    for(int i=0;i<size;i++){
           cout<<array[i]<<"\t" ; 
    }
}
void VitriDuongDautien(int array[],int size){
    int i=0 ; 
       while(i++  < size-1){
               if(array[i] > 0 ) cout<<"Vi tri: "<<(i+1)<<" voi gia tri la: "<<array[i] ; 
               return ; 
       }
}
void vitriDuongCuoiCung(int array[],int size){
    int i=size ; 
    while(i-- > 0 ){
           if(array[i] > 0 )
           {
                if(array[i] > 0 ) cout<<"Vi tri: "<<(i+1)<<" voi gia tri la: "<<array[i] ; 
               return ; 
           }
    } 
}
int Max(int array[],int size){
    int max = array[0]; 
    for(int i=1;i<size;i++){
          if(array[i] > max ) max = array[i] ; 
    }
    return max; 
}
int dem(int array[],int size)
{
    int max = Max(array,size) ; 
    int dem =   0; 
    while(size-- > -1)
    {
        if(max == array[size]) dem++ ; 
    }
    return dem ;
}
void xuatvitriMax(int array[],int size){
    int max = Max(array,size );  
    for(int i=0;i<size;i++){
        if(array[i] == max ) cout<<"vi tri cua so lon nhat: "<<(i+1)<<endl ; 
    }
}
void themPhanTu(int array[],int &size){
    int number ; 
    cout<<"Nhap gia tri: " ; 
    cin>>number ;  
    for(int i=size;i>1 ;i--){
             array[i] = array[i-1] ;  
    }
    array[0] = number ; 
    size++ ;  
}
void themPhanTuVaoViTrik(int array[],int &size){
    int k ,number; 
    do{
     cout<<"Moi nhap vi tri k: "; 
     cin>>k ;  
     } while(k<0 && k>size) ; 
     for(int i=size;i>k;i--){
         array[i] = array[i-1] ;  
     }
     cout<<"Nhap gia tri ban muon them vao o vi tri k: " ; 
     cin>>array[k] ; 
     size++ ;  
}
void xoaPhanTuDauMang(int array[],int &size)
{
     for(int i=0;i<size-1;i++){
          array[i] = array[i+1] ; 
     }
     size-- ; 
}
void xoaPhanTuTaiViTriK(int array[],int &size)
{  
       int k ; 
       cout<<"Moi nhap vi tri k: "; 
       cin>>k ; 
     for(int i=k;i<size-1;i++)
     {
          array[i] = array[i+1] ; 
     }
     size-- ; 
}
bool ktraMangCoChuaSoLe(int array[], int size){
     for(int i=0;i<size;i++){
          if((array[i] % 2) == 1 ) return true ; 
     }
     return false ;
}
int MangMoi(int array[],int size,int arraynew[])
{
        
     
}
int main(){
          int size ;  
          cout<<"Nhap so luong phan tu: " ; 
          cin>>size  ; 
          int array[100] ;  
           nhap(array,size) ;  
           xuat(array,size) ; 
           vitriDuongCuoiCung(array,size) ; 
           VitriDuongDautien(array,size) ; 
}