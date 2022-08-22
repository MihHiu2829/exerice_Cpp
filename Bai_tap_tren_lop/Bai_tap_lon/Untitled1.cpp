#include<iostream>
#include<stdlib.h>
using namespace std ;
int main()
{
	int i = 1   ;
	while(i < 1000000)
	{
	i++ ;
	int r = rand() ; 
	system("color 2") ; 
	cout<<r<<r<<r<<r<<r<<r<<r<<r<<r ;  
}
}
