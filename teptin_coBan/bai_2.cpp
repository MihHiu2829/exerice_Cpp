#include<bits/stdc++.h>
using namespace std ;  
int  main(){
    int row,col ;  
    cout<<"Nhap so dong cua ma tran: " ;  
    cin>>row ;  
    cout<<"Nhap so cot cua ma tran: " ; 
    cin>>col ;  
    FILE *file =  fopen("test.inp","w"); 
    fprintf(file,"%d  %d\n",row,col); 
    int *p = (int*) malloc(sizeof(int)*row*col) ;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            int tmp = rand() % (100) + 0 ;
              fprintf(file,"%d\t", tmp) ; 
        }
        fprintf(file,"\n"); 
    }  
    fclose(file) ;  
    FILE *f1 = fopen("test.inp","r");  
    fscanf(f1,"\n") ;  
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            fscanf(f1,"%d",(p+(i*col+j))) ;
        }
    }
     for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<(*(p+(i*col+j)))<<"\t"; 
        }
        cout<<endl ; 
     }
}