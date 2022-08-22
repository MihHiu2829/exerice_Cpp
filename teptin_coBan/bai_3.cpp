#include<bits/stdc++.h>
using namespace std ;  
int main(){
        char a[100] ;
        cout<<"Nhap vao 1 day chu de xuat ra cac nguyen am: " ; 
        gets(a);
        FILE *file = fopen("NguyenAm.txt","w");  
        for(int i=0;i< strlen(a);i++)
        {
                if(a[i] == 'u' || a[i] == 'o' || a[i] == 'e' || a[i] == 'o' || a[i] == 'i'){
                        fprintf(file,"%c",a[i]) ;  
                }else fprintf(file,"%c",' '); 
        }
        fclose(file) ; 
}