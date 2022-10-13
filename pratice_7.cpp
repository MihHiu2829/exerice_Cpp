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
		if(f == 0)
		{
			cout<<"Ban da nhap chung phan tu, ban co muon nhap lai ko?(1/0)" ; 
			cin>>f ; 
			if(f == 1 ) continue ; 
			}
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
 		else if(root->pRight == NULL) root = root->pLeft;
 		else NodeThayThe(q,root->pRight) ; 
 		delete q ;  
	 }
 }
 void menu()
{
	printf("\n\t\t\t======MENU=====");
	printf("\n\t\t\t1. Them 1 node vao cay");
	printf("\n\t\t\t2. Xoa 1 node bat ki trong cay");
	printf("\n\t\t\t3. Duyet cay theo kieu NLR");
	printf("\n\t\t\t4. Duyet cay theo kieu LNR");
	printf("\n\t\t\t5. Duyet cay theo kieu LRN");
	printf("\n\t\t\t0. Thoat chuong trinh!! ");
	printf("\n\t\t\tMoi ban chon chuc nang: ");
}
int main()
{ 
	TREE a ;    
	int x ;

	int f ;  
	do
		{
			system("cls");
			menu();
			scanf("%d",&f) ; 
			switch(f)
			{
				case 1:
					Taocay(a) ; 
					system("pause");
					break;
				case 2:
					cout<<"Nhap x de xoa: " ;
					cin>>x  ;  
					delNode(a,x);
					system("pause");
					break;
				case 3:
					NLR(a);
					printf("\n");
					system("pause");
					break;
				case 4:
					LNR(a);
					printf("\n");
					system("pause");
					break;
				case 5:
					LRN(a);
					printf("\n");
					system("pause");
					break;
				default:
					printf("\nSai chuc nang, vui long chon lai!\n");
				case 0:
					printf("\nBan da chon thoat chuong trinh!\n");
					return 0;
					break;
			}
			printf("\t\t\t====================");
			printf("\n\t\t\tMoi ban chon chuc nang: ");
		
		
	}while (f) ; 

	
}


