#include<iostream>
using namespace std ;  
int  USCLN(int a,int b){
     if (a == b) return a ; 
     if(a>b) return USCLN(a-b,b) ;  
     else return USCLN(a,b-a) ;  
}
int BCNN(int a,int b) {              // cach lam ca nhan
       return (a*b)/USCLN(a,b) ;  
}
int BSCNN(int a,int b)   // stolen dau do tren mang ! 
{
 static int i=1;
 if(a<b)
 {
  if(b%a==0) return b;
  else {
         i++;
         BCNN(a,b*i);
        }
 }
 else
 {
  if(a%b==0) return a;
  else {
         i++;
         BCNN(a*i,b);
        }
  }
}
// int BCNN_2(int a,int b)
// {
//    if(b%a == 0) return b;
//    return BCNN_2(a,b*2);
// } 
int main(){
    int a,b ;  
    cout<<"Nhap lan luot a va b: " ; 
    cin>>a>>b  ; 
    cout<<"Uoc so chung lon nhat cua "<<a<<" va "<<b<<" la:"<<USCLN(a,b) <<endl ;  
    cout<<"Boi so chung nho nhat cua "<<a<<" va "<<b<<" la:"<<BSCNN(a,b) ;  
}