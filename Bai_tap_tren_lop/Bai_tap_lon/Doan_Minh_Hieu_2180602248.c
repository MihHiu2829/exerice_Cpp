#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void nhapMang(int a[], int n, int i) // cau 1
{
    if (i == n)
        return;
    printf("Nhap phan tu thu A[%d] = ", i);
    scanf("%d", &a[i]);
    nhapMang(a, n, i + 1);
}
void xuatMang(int A[], int n, int i)
{ // cau 2
    if (i == n)
        return;
    printf("%5d", A[i]);
    xuatMang(A, n, i + 1);
}
int tinhTong(int A[], int n, int i)
{ // cau 3
    if (i == n)
        return 0;
    return A[i] + tinhTong(A, n, i + 1);
}
int tinhTongLe(int A[], int n, int i)
{ // cau 5
    if (i == n)
        return 0;
    return A[i] % 2 == 1 ? A[i] + tinhTongLe(A, n, i + 1) : tinhTongLe(A, n, i + 1);
}
int timPhanTuLonNhat(int A[], int n, int i, int max)
{ // cau 11
    if (n == i)
        return max;
    return A[i] > max ? timPhanTuLonNhat(A, n, i + 1, A[i]) : timPhanTuLonNhat(A, n, i + 1, max);
}
int tinhTongChan(int A[], int n, int i) // cau 4
{
    if (i == n)
        return 0;
    return A[i] % 2 == 0 ? A[i] + tinhTongChan(A, n, i + 1) : tinhTongChan(A, n, i + 1);
}
int isPrime(int n)
{
    if (n < 2)
        return 0;
        int i ;   
    for ( i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
int tinhTongSNT(int A[], int n, int i)
{ // cau 6
    if (i == n)
        return 0;
    return isPrime(A[i]) == 1 ? A[i] + tinhTongSNT(A, n, i + 1) : tinhTongSNT(A, n, i + 1);
}
int phanTuChanDauTien(int A[], int n, int i)
{ // cau 7
    if (i == n)
        return -1;
    return A[i] % 2 == 0 ? A[i] : phanTuChanDauTien(A, n, i + 1);
}
int phanTuLeDauTien(int A[], int n, int i)
{ // cau 8
    if (i == n)
        return -1;
    return A[i] % 2 == 0 ? A[i] : phanTuLeDauTien(A, n, i + 1);
}
int phanTuNguyenToDauTIen(int A[], int n, int i) // cau 9
{

    if (i == n)
        return -1;
    return isPrime(A[i]) == 1 ? A[i] : phanTuNguyenToDauTIen(A, n, i + 1);
}
int phanTuChanCuoiCung(int A[], int n) // cau 10
{
    if (n < 0)
        return -1;
    return A[n] % 2 == 0 ? A[n] : phanTuChanCuoiCung(A, n - 1);
}
int demPhanTuChan(int A[], int n, int count) // cau 12
{
    if (n < 0)
        return count;
    return A[n] % 2 == 0 ? demPhanTuChan(A, n - 1, count + 1) : demPhanTuChan(A, n - 1, count);
}
int demPhanTuLonNhat(int A[], int n, int max, int i) // cau 13
{
    if (i == n)
        return 0;
    return max == A[i] ? 1 + demPhanTuLonNhat(A, n, max, i + 1) : demPhanTuLonNhat(A, n, max, i + 1);
}
int main()
{
    int n;
    int a[100];
    do
    {
        printf("Nhap so luong phan tu cua mang: ");
        scanf("%d", &n);
        if (n < 1)
        {
            printf("Ban nhap sai, vui long nhap lai.\n");
        }
    } while (n < 1);
    nhapMang(a, n, 0);
    xuatMang(a, n, 0);
    printf("3. Tong cac phan tu co trong mang : %d\n", tinhTong(a, n, 0)) ; 
    printf("4. Tong cac phan tu chan co trong mang : %d\n", tinhTongChan(a, n, 0));
    printf("5. Tong cac phan tu le co trong mang : %d\n", tinhTongLe(a, n, 0));
    printf("6. Tong cac phan tu so nguyen to co trong mang : %d\n", tinhTongSNT(a, n, 0));
    printf("7. Phan tu chan dau tien co trong mang la : %d \n", phanTuChanDauTien(a, n, 0));
    printf("8. Phan tu le dau tien co trong mang la : %d \n", phanTuLeDauTien(a, n, 0));
    printf("9. Phan tu nguyen to dau tien co trong mang la : %d \n", phanTuNguyenToDauTIen(a, n, 0));
    printf("10. Phan tu chan cuoi cung co trong mang la : %d \n", phanTuChanCuoiCung(a, n));
    printf("11. Phan tu lon nhat co trong mang la : %d \n", timPhanTuLonNhat(a, n, 0, 0));
    printf("12. So phan tu chan co trong mang la : %d \n", demPhanTuChan(a, n, 0));
    printf("13. So phan lon nhat co trong mang la : %d \n", demPhanTuLonNhat(a, n, timPhanTuLonNhat(a, n, 0, 0), 0));
}s