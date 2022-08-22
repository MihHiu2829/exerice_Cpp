#include <iostream>
#include <stdlib.h>
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
void inPhanTuBien(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0 || i == (n - 1) || j == (n - 1))
                cout << a[i][j] << "\t";
            else
                cout << "  \t";
        }
        cout << endl;
    }
}
int sum(int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0 || i == (n - 1) || j == (n - 1))
                sum += a[i][j];
        }
    }
    return sum;
}
bool ktdoixung(int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i][j] != a[j][i])
                return 0;
    return 1;
}
int main()
{
    int n;
    cout << "Nhap kich thuoc vuong cua mang: ";
    cin >> n;
    nhap(n);
    inPhanTuBien(n);
}