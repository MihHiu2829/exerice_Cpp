#include<bits/stdc++.h>
using namespace std ; 

typedef struct date{
	int ngay, thang, nam ; 
}date;
typedef struct sachMH{
	char maSach[10] ; 
	char tenSach[30] ;  
	int SoLuong ;  
	char chuyenNghanh[10] ;  
	char donVi[20] ;  
	date XuatBan ;  
}book;

typedef struct Node{
	book info ; 
	Node *pNext; 
}NODE ;
typedef struct List{
		 Node *pHead  ; 
		 Node *pTail ;  
}LIST;
void initLIST(LIST &a)
{
	a.pHead = a.pTail = NULL ;  
}
void InsertBook(book &a)
{
	cout<<endl ; 
	cout<<"Pls, enter ID book: " ; 
	fflush(stdin) ; 
	gets(a.maSach); 
	cout<<"Pls, enter name book: " ; 
	fflush(stdin) ;  
	gets(a.tenSach) ;  
	cout<<"Pls , enter number of book: " ; 
	cin>>a.SoLuong ;  
	cout<<"Pls, enter major of book: ";  
	fflush(stdin) ;  
	gets(a.chuyenNghanh) ; 
	cout<<"Pls, nhap don vi cua quyen sach: " ; 
	fflush(stdin) ; 
	gets(a.donVi) ; 
	cout<<"nhap ngay, thang nam xuat ban: " ; 
	scanf("%d/%d/%d", &a.XuatBan.ngay, &a.XuatBan.thang, &a.XuatBan.nam) ;   
}
Node* createNode(book x)
{
	Node *p = new Node ; 
	p->info = x ; 
	p->pNext = NULL ; 
	return p ;  
}
void  addHead(LIST &a,Node *p)
{
	if(a.pHead == NULL )
	{
		a.pHead = p  ; 
		return ; 
	}
	p->pNext = a.pHead ;  
	a.pHead =  p  ;   
}
void Nhap1CuonSach(LIST &A)
{
	book a ;
	InsertBook(a) ;  
	Node *p = createNode(a)  ;
	addHead(A,p) ; 
}
void NhapSach(LIST &A)
{
	int n ; 
	cout<<"Nhap so luong:"; 
	cin>>n ; 
	for(int i=0;i<n;i++)
	{
		Nhap1CuonSach(A); 
	}
}
void xuat1quyensach(book a)
{
	printf("%-20s|%-20s|%-10s|%-15s|%-15s|%-20s\n","Ma sach","Ten sach","So luong","Chuyen Nganh","Don vi","Xuat Ban"); 
	printf("%-20s|%-20s|%-10d|%-15s|%-15s|%-2d/%-2d/%-4d\n",a.maSach,a.tenSach,a.SoLuong,a.chuyenNghanh,a.donVi,a.XuatBan.ngay,a.XuatBan.thang,a.XuatBan.nam) ; 
}

void xuat1DanhSach(LIST a)
{
	if(a.pHead == NULL)
	{
		cout<<"Pls, enter the List  then display List!\n" ; 
		return ; 
	}
	printf("\t%-20s|%-20s|%-10s|%-15s|%-15s|%-20s\n","Ma sach","Ten sach","So luong","Chuyen Nganh","Don vi","Xuat Ban"); 
 		for(Node *p = a.pHead; p ;p= p->pNext)
 		{
 			printf("\t%-20s|%-20s|%-10d|%-15s|%-15s|%-2d/%-2d/%-4d\n",p->info.maSach,p->info.tenSach,p->info.SoLuong,p->info.chuyenNghanh,p->info.donVi,p->info.XuatBan.ngay,p->info.XuatBan.thang,p->info.XuatBan.nam) ; 
		 }
}
void swapNpde(book &a,book &b)
{
	book tmp =  a;  
	a = b  ; 
	b = tmp ; 
}
void findXandXshower(LIST &a)
{
	char x[30] ;  
	cout<<"Nhap khoa x ban muon tim kiem: " ; 
	fflush(stdin) ;  
	gets(x) ;  
	for(Node *p= a.pHead;p;p=p->pNext)
	{
		if(strcmp(p->info.donVi,x) == 0)
		{
			cout<<"\nCo don vi khoa "<<x<<endl ; 
		 		for(Node *q= a.pHead;q;q=q->pNext)
		 		{
		 			if(strcmp(q->info.donVi,x) == 0 )
		 			{
		 				xuat1quyensach(q->info) ; 
					 }
				 }
				 
		}else cout<<"Khong co khoa don vi "<<x<<endl ;  
	}
}//nhattruong200403@gmail.com
void findXthenInserYRIGHT(LIST &a, char y[]){
		
		book ax  ; 
		InsertBook(ax); 
	  Node *q = createNode(ax) ;   
		
		for(Node *p = a.pHead ; p ; p = p->pNext)
		{
				if(strcmp(p->info.tenSach,y) == 0 )
				{
					 
					if(p->pNext == NULL)
					{
							p->pNext = q ;  
					}else {
							q->pNext = p->pNext ;  
						p->pNext = q ;  
					}
						cout<<"Da chen quyen sach X sau quyen sach Y"<<endl ; 
					return ; 
				}
		}
		Node *tmp  ;  
			for(Node *p = a.pHead;p;p=p->pNext)
			{
				tmp = p  ;  
			}
			tmp->pNext = q ;  
	}
void findX(LIST &a){
	cout<<"Vui long nhap ten sach : "; 
	char x[30] ; 
	fflush(stdin);
	gets(x);
	findXthenInserYRIGHT(a,x);
}
void sortDown(LIST &a)
{
	for(Node *p = a.pHead;p;p=p->pNext)
	{
		for(Node *q = p->pNext;q;q=q->pNext)
		{
			if(p->info.SoLuong < q->info.SoLuong)
			{
				swapNpde(p->info,q->info) ; 
			}
		}
	}
}
int  main()
{
	LIST A ;  
	initLIST(A); 
	
//NhapSach(A) ; 
//xuat1DanhSach(A) ; 
//cout<<endl;  
//cout<<"Danh sach sap xep giam: ";  
//sortDown(A) ; 
//xuat1DanhSach(A) ; 
int chon;
while(true){
char x[20];
printf("\n-----------MENU QUAN LY SACH-----------------\n");
printf("1/Nhap sach\n");
printf("2/Xuat danh sach\n");
printf("3/Sap xep giam dan so luong sach\n");
printf("4/Tim sach thuoc don vi khoa\n");
printf("5/Chen 1 cuon sach\n");
printf("0/THOAT!!!\n");
printf("--->Nhap lua chon cua ban :");
scanf("%d",&chon);
switch(chon){
case 1:
Nhap1CuonSach(A) ; 
break;
case 2:
printf("\t\t---------Danh sach cac sach---------\n");
xuat1DanhSach(A) ; 
break;
case 3:
	sortDown(A) ; 
printf("\n\t\t--------Danh sach sau khi sap xep----------\n");
xuat1DanhSach(A) ;
break;
case 4:
findXandXshower(A) ;
break;
case 5:
findX(A) ; 
case 0:
return 0;
}
return 0;

}

}
