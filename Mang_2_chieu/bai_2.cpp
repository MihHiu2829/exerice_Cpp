#include <iostream>
#include <stdlib.h> // thu vien chua ham rand
using namespace std;
static int a[15][15];
void nhap(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = 1 + rand() % 100;
        }
    }
}
void xuat(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}
void lietkecheochinh(int n)
{
    cout << "cac phan tu tren duong treo chinh. ";
    while (n > 0)
    {
        cout << a[n][n] << "\t";
        n--;
    }
}
void lietkeCheoPhu(int n)
{
    cout << "Cac phan tu tren duong treo phu: ";
    int i = 0, j = n - 1;
    while (n > 0)
    {
        cout << a[i++][j--] << "\t";
        n--;
    }
}
int tongtrendongk(int n, int k)
{
    int i = k, sum = 0;
    for (int j = 0; j < n; j++)
    {
        sum += a[i][j];
    }
    return sum;
}
void tongPhanTuTrenMoiDong(int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum += a[i][j];
        }
        cout << "tong dong thu " << i + 1 << ": " << sum << endl;
        sum = 0;
    }
}
void xuat1dongk(int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[k][i] << " ";
    }
    cout << endl;
}
void tongTrenCacDongLonNhat(int n)
{
    int max = tongtrendongk(n, 0);

    for (int i = 1; i < n; i++)
    {
        if (tongtrendongk(n, i) > max)
            max = tongtrendongk(n, i);
    }
    cout << "cac dong lon nhat: " << endl;
    for (int i = 0; i < n; i++)
    {
        if (max == tongtrendongk(n, i))
        {
            xuat1dongk(n, i);
        }
    }
}
int main()
{
    int n;
    cout << "Nhap vao so cap cua ma tran vuong: ";
    cin >> n;
    nhap(n);
    xuat(n);
}