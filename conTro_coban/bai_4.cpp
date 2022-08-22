#include<iostream>
#include<bits/stdc++.h>
using namespace std ; 

int main(){
     char ten[30] ,*p;  
     fflush(stdin) ;  
     gets(ten);
     ten[0]  = toupper(ten[0]); 
      for(int i=1 ;i< strlen(ten);i++){
           if(ten[i] >= 65 && ten[i] <=90) {
               if(ten[i-1] != ' ') ten[i] += 32 ; 
           }
      }
      for(int i=1;i<strlen(ten)-1;i++){
          if(ten[i] == ' '){
              if(ten[i+1] >= 65+32 && ten[i+1] <=90+32) {
                  ten[i+1] -= 32 ; 
          }
      }}
      puts(ten); 
}