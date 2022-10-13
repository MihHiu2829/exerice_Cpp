#include<bits/stdc++.h>
using namespace std ; 
typedef struct Node{
	int info ;  
	Node *pNext ;  
};
typedef struct Stack{
	Node *pHead ; 
};
void initStack(Stack &a)
{
			a.pHead =  NULL ;  	
}
Node* createNewNode(int x)
{
		Node *p = new Node ; 
		p->info = x ;  
		p->pNext = NULL ;  
		return p ;  
}
int isEmpty(Stack a)
{
	if(a.pHead == NULL )
	 return 1 ;  
	 return 0 ;  
}
void Push(Stack &a, int x)
{
	Node *p = createNewNode(x) ; 
	if(isEmpty(a))
	{
		a.pHead = p ; 
	 }else {
	 	p->pNext = a.pHead ; 
	 	a.pHead =  p ;   
	 }	
}
int Pop(Stack &a)
{
	 if(isEmpty(a))
	 {
	 	return -1 ; 
	 }else {
	 	 Node *p = a.pHead ;  
			a.pHead = a.pHead->pNext ;  
			int x = p->info  ; 
			delete p  ;
			return x ;  
	 }
}
int Top(Stack a)
{
	if(isEmpty(a))
	return -1 ;  
	return a.pHead->info ;  
	
}
int main()
{
	cout<<"Pratice 2"<<endl ; 
	Stack a ; 
	initStack(a); 
 		int x , n  ;	
		cout<<"Nhap n: " ; 
		cin>>n ;  
		for(int i=0;i<n;i++)
		{
			cout<<"Nhap x: "  ; 
			cin>>x ;  
			Push(a,x) ;  
		  }  
		
 
		cout<<endl<<"Gia tri da nhap:"<<endl ; 
		do{
			 x = Pop(a); 
			 if(x == -1 ) break  ;  
			 cout<<x<<"  " ; 
		}while(true) ;  
	
	
	
}
