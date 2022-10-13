#include<bits/stdc++.h> 
using namespace std ; 
typedef struct Node{
	int data ; 
	Node *pLeft ;
	Node *pRight ;
}NODE;
typedef Node* TREE ; 

void InitTree(TREE &root)
{
		root = NULL ;   
}
Node* SearchNode(TREE root,int x)
{
	if(root)
	{
		if(root->data == x) 
				return root ;  
		if(root->data > x ) return SearchNode(root->pLeft ,x) ;
		if(root->data < x) return SearchNode(root->pRight,x) ;  
	}
	return NULL ; 
}
Node* createNewNode(int x)
{
	Node *p  = new Node ; 
	p->pLeft = NULL ;  
	p->pRight = NULL ; 
	p->data = x ; 
	return p ; 
}
int InsertNode(TREE &root,int x)
{
	if(root == NULL)
	{
			root = createNewNode(x) ;  
	return 1 ;  
	}
	
	if(root != NULL )
	{
		if(root->data == x ) return 0 ;  
		else if(root->data > x ) return InsertNode(root->pLeft,x) ; 
		else return InsertNode(root->pRight,x) ; 
	}

} 
void Taocay(TREE &root)
{
	int x, f  ;  
	InitTree(root) ; 
	do{
		printf("\n Nhap vao gia tri cua Node:  ");  
		cin>>x ;  
		f = InsertNode(root,x) ; 
	}while(f) ; 

}
 
 void NLR(TREE root)
 {
 	if(root)
 	{
 		printf("%d\t",root->data) ;
 		NLR(root->pLeft) ; 
 		NLR(root->pRight) ; 
	 }
 }
 
 void LNR(TREE root)
 {
 	if(root)
 	{
 		LNR(root->pLeft) ;  
 		printf("%d\t",root->data) ; 
 		LNR(root->pRight) ;  
	 }
 }
 void LRN(TREE root)
 {
 	if(root)
 	{
 		LRN(root->pLeft);
 		LRN(root->pRight) ;
 		printf("%d\t",root->data) ; 
 		
	 }
 }
 int chieucao(TREE root)
 {
 	if(!root) return 0 ; 
 	 int a = chieucao(root->pLeft) ; 
 	 int b = chieucao(root->pRight) ; 
 	 if (a>b) return (a+1) ; 
 	 return (b+1) ; 
 }
 void DemNode(TREE root,int &d)
 {
 	if(root)
 	{
 		d++ ;  
 		DemNode(root->pLeft,d) ;
 		DemNode(root->pRight,d) ; 
	 }
 }
 void Inchan(TREE root)
 {
 	if(root)
 	{
 		if(root->data%2 ==0 )
 				printf("%d",root->data) ; 
 			Inchan(root->pLeft); 
 			Inchan(root->pRight) ;
	 }
 }
 void DemNodeLa(TREE root,int &d)
 {
 	if(root)
 	{
 		if((!root->pLeft) && (!root->pRight)) 
 		{
 			d++ ;  
 			return  ;
		 }
		 DemNodeLa(root->pLeft,d) ;  
		 DemNodeLa(root->pRight,d) ;  
	 }
 }
 
 void NodeThayThe(TREE &q, TREE &p)
 {
 	if(p->pLeft != NULL)
 				NodeThayThe(q,p->pLeft) ; 
 	else {
 		q->data = p->data ;  
 		q = p  ;  
 		p = p->pRight ;
 		
	 }
 }
 void delNode(TREE &root,int x)
 {
 	if(root== NULL) return ;  
 	if(root->data > x ) delNode(root->pLeft,x) ;  
 	if(root->data < x ) delNode(root->pRight, x) ;  
 	if(root->data == x )
 	{
 		NODE *q = root; 
 		if(root->pLeft == NULL) root = root->pRight ;  
 		if(root->pRight == NULL) root = root->pLeft;
 		else NodeThayThe(q,root->pRight) ; 
 		delete q ;  
	 }
 }
int main()
{ 
	TREE a ;
	cout<<"Hello"<<endl ;    
	Taocay(a) ; 
	cout<<endl ;
	LNR(a) ;  
	delNode(a,8) ; 
	cout<<endl ;  
	LNR(a); 
}
