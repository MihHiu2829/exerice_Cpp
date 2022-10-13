#include<bits/stdc++.h>
using namespace std ; 
typedef struct Node{
	int info ; 
	Node *pNext ; 
}NODE;

typedef struct LIST{
	NODE *pHead ;  
	NODE *pTail ;  
}LIST;

void init(LIST &a)
{
	a.pHead = a.pTail = NULL ; 
}

Node* createNewNode(int x)
{
		Node *p = new Node ; 
		if(p == NULL) 
			return NULL ;  
		p->info = x ;  
		p->pNext = NULL ; 
		return p ;  	
}
void addHead(Node *p,LIST &a)
{
	if(a.pHead == NULL ) 
	{
				a.pHead = p;
	}else{
		p->pNext = a.pHead ;  
		a.pHead = p ;  
	}
}
void inputAhead(LIST &a)                                     // insert head 
{
	int x ; 
	cout<<"Please, Enter your data: "; 
	cin>>x ; 
	Node *p = createNewNode(x); 
	addHead(p,a) ;  
}
void displayNodeList(LIST a) 
{
		cout<<endl<<"Show info: "<<endl ; 
		for(Node *p= a.pHead ; p ; p=p->pNext)
		{
			cout<<p->info<<" ";  
		}
}
void swapNode(int &a,int &b)
{
	 int tmp = a ;  
	 a =  b  ; 
	  b = tmp ;   
	 
}
void sortUp(LIST &a)//=========================================================================== sap xep tang dan 
{
	for(Node *p=a.pHead;p;p=p->pNext)
	{
		for(Node *q= p->pNext ; q ; q=q->pNext)
		{
			if(p->info > q->info)
			{
				swapNode(p->info,q->info) ; 
			}
		}
	}
}


void findXthenInsertYLEFT(LIST &a,int x)
{
	Node *tmp = NULL ;  
	for(Node *p = a.pHead; p ; p=p->pNext)
	{
			if(p->info == x )
			{
				 int z ; 
				 cout<<"Please, enter values: " ; 
				  cin>>z ;  
				  Node *q = createNewNode(z) ;  
				  
				 if(tmp == NULL)
				 {
				 	addHead(q,a) ; 
				 }else {
				 	q->pNext = tmp->pNext ;  
				 	tmp->pNext = q ;  
				 }
				 return ; 
			}
		tmp =  p;  
	}
}
void findXthenInserYRIGHT(LIST &a,int x){
	int z ; 
				 cout<<"Please, enter values: " ; 
				  cin>>z ; 
	  Node *q = createNewNode(z) ;  
		
		for(Node *p = a.pHead ; p ; p = p->pNext)
		{
				if(p->info == x )
				{
					 
					if(p->pNext == NULL)
					{
							p->pNext = q ;  
					}else {
							q->pNext = p->pNext ;  
						p->pNext = q ;  
					}
					return ; 
				}
		}	
}
void findXtheInsertYSHOW(LIST &a)
{
	int x ; 
	cout<<"nhap x: " ; 
	cin>>x ; 
	findXthenInserYRIGHT(a,x) ;   
}
void DeleteNodeThenFIndX(LIST &a,int x)
{
	 Node *tmp = NULL ;  
	 for(Node *p = a.pHead ; p ; p=p->pNext)
	 {
	 	 if(p->info == x)
	 	 {
	 	 	if(tmp == NULL)
	 	 	{
	 	 		Node *q =  a.pHead ;  
	 	 		a.pHead = a.pHead->pNext ;
	 	 		delete(q) ;   
	 	 		return ;  
			  }else if ( p->pNext == NULL)
			  {
			  	tmp->pNext = NULL ;  
			  	delete(p) ;  
			  	return ;  
			  }
			      tmp->pNext = p->pNext ;  
			      delete p ;  
			  return ; 
		  }
		  tmp = p  ;  
	 }
}
void DeleteNodeWheFindX(LIST &a)
{
	int x ; 
	cout<<"Enter x: ";  
	cin>>x ;  
	DeleteNodeThenFIndX(a,x) ;  
}
int main()
{
	 cout<<"Hello world"<<endl ; 
	 LIST a ;  
	 init(a) ;  
	 inputAhead(a);
 	 inputAhead(a); 
	 inputAhead(a);
	 inputAhead(a);
	 inputAhead(a);
	 inputAhead(a);
//	 sortUp(a) ;  
//			findXtheInsertYSHOW(a) ;  
DeleteNodeWheFindX(a) ; 
	 displayNodeList(a) ; 
	 

}
