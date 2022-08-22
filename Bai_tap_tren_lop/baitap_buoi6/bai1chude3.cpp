#include<bits/stdc++.h>
void nhap(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("a{%d]: ",i) ;   
        scanf("%d",&a[i]) ;
    }
}
void xuat(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]) ;
    }
}
void daonguoc(int a[],int n)
{
    int mid = n/2 , tmp  ;
    for(int i=0;i<=mid;i++)
    {
        tmp = a[i] ;  
        a[i] = a[n-1-i] ;  
        a[n-1-i]  =  tmp ;  
    } 
}
int giatrichanlonnhat(int a[],int n)
{
    int max = -1  ; 
    for(int i=0;i<n;i++)
    {
        if(a[i] % 2 == 0 )
        {
            if(a[i] > max )
                max = a[i] ;  
        }
    }
    return max ;  
}
int main(){
    int n ,  a[100]  ; 
    printf("Nhap n:\n")  ; 
    scanf("%d",&n) ;  
    nhap(a,n) ; 
    xuat(a,n) ; 
    printf("Mang sau khi dao nguoc! \n");
    daonguoc(a,n) ; 
    xuat(a,n) ; 
    printf("\nPhan tu chan lon nhat: %d",giatrichanlonnhat(a,n)) ; 
}
