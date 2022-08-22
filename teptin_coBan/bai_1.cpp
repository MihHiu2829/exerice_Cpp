#include<bits/stdc++.h>         // dung c++ tien hon ! 
using namespace std ;  
bool prime(int a){
    if(a<2) return false ;  
    for(int i=2;i<sqrt(a);i++){
        if(a % i == 0 ) return false;  
    }
    return true ;  
}
int  main(){ 
     FILE *file = fopen("test.txt","r+"); 
     int  n  ;  
     fscanf(file,"%d",&n) ; 
      int a[n] ;  
       for(int i=0;i<n;i++){
           fscanf(file,"%d",&a[i]) ;
           cout<<a[i]<<" ";  
       } 
           fclose(file) ; 
        // FILE *file1 = fopen("test1.txt","w"); 
        file = fopen("test1.txt","w") ; 
       for(int i=0;i<n;i++){
             if(prime(a[i])) fprintf(file,"%d\t",a[i]) ;  
       }
       fclose(file) ;   
}