#include<bits/stdc++.h>
using namespace std ; 
int  main(){
    char s1[30],s2[30] ;  
     cout<<"Nhap chuoi s1: "; 
     fflush(stdin) ; 
     gets(s1) ;  
     cout<<"Nhap chuoi s2: " ;
     gets(s2);
     cout<<"chuoi 1:"<<s1<<endl ; 
     cout<<"chuoi 2:"<<s2<<endl ; 
     cout<<"do dai cua chuoi 1: "<<strlen(s1)<<endl ;  
     cout<<"do dai cua chuoi 2: "<<strlen(s2)<<endl ; 
     cout<<"So sanh chuoi s1 va s2: "<<stricmp(s1,s2)<<endl ;  
     cout<<"Noi chuoi 2 vao chuoi 1: "<<strcat(s1,s2)<<endl ; 
     cout<<s1<<endl;
     cout<<"Tim kiem su co mat cua chuoi 2 ben trong chuoi 1: "<<strstr(s1,s2)<<endl;  
     cout<<"Tim kiem su co mat cua chuoi 1 ben trong chuoi 2: "<<strstr(s2,s1)<<endl;  

}