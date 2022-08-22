#include<bits/stdc++.h>
using namespace std ; 
double cur(int n,int i = 0)
{
	if (n == 0) return 0 ;  
	double tmp = 1/(pow((n+i),2) + n)  ;   
	return tmp + cur(--n,++i) ;  
}
int main(){
	int n ;   
	cin>>n ;  
	cout<<cur(n) ;    
} 
