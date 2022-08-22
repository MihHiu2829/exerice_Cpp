#include<bits/stdc++.h>
using namespace std  ; 
void solve(long n)
{
      if(n%2 == 1 )
	      {
	      	cout<<n ;  
	      	return  ;  
		   }else 
		   {
		   	  while(true) 
		   	  {
		   	  	if( n%2 != 0 ) {
		   	  		    cout<<n ;  
		   	  		    break  ; 
					 }
					 else n/=2 ; 
				 }
		   }
}
int main()
{
	int n ; 
	cin>>n ;  
	solve(n) ; 
 } 
