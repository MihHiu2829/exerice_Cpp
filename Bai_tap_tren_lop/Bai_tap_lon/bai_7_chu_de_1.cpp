#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int KTSNT(int n)
{
    if (n < 2)
        return 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

// int Reverse(int n)
// {
//     int reNum = n % 10;
//     n /= 10;
//     int last;
//     while (n > 0)
//     {
//         last = n % 10;
//         n /= 10;
//         reNum = reNum * 10 + last;
//     }
//     return reNum;
// }
int Reverse(int n)
{
    /*
        Lấy chữ số cuối cùng bằng cách chia dư cho 10
        Bỏ chữ số cuối cùng bằng cách chia cho 10
     */
    int reNum = n % 10; // B1: Lấy chữ số cuối cùng
    n /= 10;            // Bỏ chữ số cuối cùng
    int last;
    while (n > 0)
    {
        last = n % 10;             // Lấy chữ số cuối cùng
        n /= 10;                   // Bỏ chữ số cuối cùng
        reNum = reNum * 10 + last; // Chính là các bước 2 3 4
    }
    return reNum;
}
void nhapMang(int a[], int &n)
{
    printf("Nhap so luong phna tu trong mang:  ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}
void xuatMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%10d", a[i]);
    }
}
int ktraNguyenToVaNguyenToDaoNguoc(int a[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (KTSNT(a[i]) == 1 && KTSNT(Reverse(a[i])))
        {
            count++;
        }
    }
    return count;
}
int tongsonguyentodaonguoc(int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (KTSNT(a[i]) == 1 && KTSNT(Reverse(a[i])))
        {
            sum += a[i];
        }
    }
    return sum;
}
void sortUp(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n+1;j++)
        {
            if(a[i] < a[j])
             {
                 int tmp  = a[i] ;  
                 a[i]  = a[j] ;  
                 a[j]  = tmp ;  
             }
        }
    }
}
void timPhanTuCoLanXuatHienNhieuNhatTrongMang(int a[],int n)
{
    sortUp(a,n) ; 
    int count   = 1 ;   
     int max[]  ={0,0} ;   
    for(int i=0;i<n;i++)
    {
        if(a[i] == a[i-1]) count++   ; 
        else{
            if(max[1] < count )
            {
                max[0]  = a[i] ;  
                max[1]  = count ; 
            }
            count = 1;  
        }
    }
     printf("Phan tu %d xuat hien nhieu nhat trong mang voi %d lan\n", max[0], max[1]);
}
void insertionSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
 
       /* Di chuyển các phần tử có giá trị lớn hơn giá trị 
       key về sau một vị trí so với vị trí ban đầu
       của nó */
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}
int main()
{
    int a[100], n;
    nhapMang(a, n);
    xuatMang(a, n);
    printf("Dem so nguyen to va so nguyen to dao nguoc trong mang: %d\n", ktraNguyenToVaNguyenToDaoNguoc(a, n));
    printf("Tong cac so nguyen to co the dao lai van la so nguyen to la: %d\n", tongsonguyentodaonguoc(a, n));
}