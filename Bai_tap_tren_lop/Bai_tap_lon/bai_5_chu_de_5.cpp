#include<stdio.h>
#include<stdlib.h>
#include<math.h>
 int isPrime(int n)
 {
     if(n<2) return 0  ; 
     for(int i=2;i<=sqrt(n);i++)
     {
         if(n%i==0) 
            return 0 ; 
     }
     return 1; 
 }
 int countPrime(int a[][100],int m,int n)
 {
     int count = 0 ; 
     for(int i=0;i<m;i++)
     {
         for (int j=0;j<n;j++)
         {
             if(isPrime(a[i][j]))
                    count++ ;  
         }
     }
     return count ; 
 }
 int Max(int a[][100],int m , int n)
 {
     int sum = 0  , max = 0 ; 
     for(int i=0;i<m;i++){
         sum=0 ; 
                 for(int j=0;j<n;j++)
            {
                        sum+= a[i][j] ;  
            }
            if(sum > max) max =  sum ; 
     }
        return max ;  
 }
int main()
{
    FILE *pac ;  
    pac = fopen("table.txt","r");
    int m , n  , a[100][100]; 
    fscanf(pac ,"%d",&m);
    fscanf(pac,"%d",&n);
    // printf("%d va %d",m,n) ; 
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            fscanf(pac,"%d",&a[i][j]);  
        }
    }
    fclose(pac) ;
    printf("Mang vua doc trong file la \n") ;  
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%10d",a[i][j]) ;
        }
        printf("\n\n"); 
    }  
    printf("\nco %d phan tu nguyen to trong mang \n", countPrime(a,m,n)); 
    printf("Gia tri co phan tu lon nhat %d trong tong cac dong! \n", Max(a,m,n)); 
}