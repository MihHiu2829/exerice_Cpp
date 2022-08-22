#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef struct thongtin
{
    string mathuebao, HoVaTenChuThueBao, date;
    int timeNoiMang, timeNgoaiMang;
    bool loaiThueBao;

} in4;
void inputthuepao(in4 &thuebao)
{
    fflush(stdin);
    cout << "Nhap ma the bao: ";
    getline(cin, thuebao.mathuebao);
    cout << "Nhap ho va ten cua chu thue bao: ";
    getline(cin, thuebao.HoVaTenChuThueBao);
    cout << "Nhap ngay thang nam dang ki thue bao: form(XX/XX/XXXX) ";
    getline(cin, thuebao.date);
    cout << "Loai thue bao " << endl
         << "1.tra truoc" << endl
         << "0.tra sau" << endl
         << "Moi nhap (1/0): ";
    int select;
    cin >> select;
    if (select == 1)
        thuebao.loaiThueBao = true;
    else
        thuebao.loaiThueBao = false;
    cout << "Thoi gian goi noi mang la: (phut) ";
    cin >> thuebao.timeNoiMang;
    cout << "Thoi gian goi ngoai mang la: (phut)";
    cin >> thuebao.timeNgoaiMang;
}
void inputthuepaoS(in4 thuebao[], int n)
{
    for (int i = 0; i < n; i++)
    {
        inputthuepao(thuebao[i]);
    }
}
void xuat1thuebao(in4 ab)
{
    printf("%30s %30s %30s %30d %30d %30d\n", ab.mathuebao.c_str(), ab.HoVaTenChuThueBao.c_str(), ab.date.c_str(), ab.loaiThueBao, ab.timeNoiMang, ab.timeNgoaiMang);
}
void xuatThongTinCacThueBao(in4 thuebao[], int n)
{
    printf("%30s %30s %30s %30s %30s %30s\n", "Ten thue bao", "Ten chu thue bao", "Ngay dang ki", "Loai thue bao", "tgian noi mang", "tgian ngoai mang");
    for (int i = 0; i < n; i++)
    {
        xuat1thuebao(thuebao[i]);
    }
}
void them1biuKien(in4 thuebao[], int &n)
{
    inputthuepao(thuebao[n]);
    n++;
}
void sort(in4 thuebao[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
            if (thuebao[i].mathuebao.compare(thuebao[j].mathuebao) > 0)
                swap(thuebao[i], thuebao[j]);
    }
}
void timThueBao(in4 thuebao[], int n)
{
    string ten;
    cout << "Nhap ten muon tim : ";
    fflush(stdin) ; 
    getline(cin,ten);
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (thuebao[i].HoVaTenChuThueBao.compare(ten) == 0)
        {
            cout << "Da tim thay thue bao co ten ban nhap! " << endl;
            printf("%30s %30s %30s %30s %30s %30s\n", "Ten thue bao", "Ten chu thue bao", "NgaySinh", "Loai thue bao", "tgian noi mang", "tgian ngoai mang");
            xuat1thuebao(thuebao[i]);
            flag = 1;
        }
    }
    if (!flag)
        cout << "Khong co ten ban tim kiem";
}
void xuatthuebaotheoloai(in4 thuebao[], int n)
{
here:
    cout << "Ban muon xuat loai thue bao nao? " << endl;
    cout << "Chon 1: xuat thue bao tra truoc." << endl
         << "Chon 2: xuat thue bao tra sau. " << endl
         << "Moi nhap lua chon: ";
    int select;
    cin >> select;
    if (select == 1)
    {
        cout << "Thue bao tra truoc! " << endl;
        printf("%30s %30s %30s %30s %30s %30s\n", "Ten thue bao", "Ten chu thue bao", "NgaySinh", "Loai thue bao", "tgian noi mang", "tgian ngoai mang");
        for (int i = 0; i < n; i++)
        {
            if (thuebao[i].loaiThueBao == 1)
                xuat1thuebao(thuebao[i]);
        }
    }
    else if (select == 2)
    {
        cout << "Thue bao tra sau! " << endl;
        printf("%30s %30s %30s %30s %30s %30s\n", "Ten thue bao", "Ten chu thue bao", "NgaySinh", "Loai thue bao", "tgian noi mang", "tgian ngoai mang");
        for (int i = 0; i < n; i++)
        {
            if (thuebao[i].loaiThueBao == 0)
                xuat1thuebao(thuebao[i]);
        }
    }
    else
    {
        cout << "nhap sai, vui long nhap lai, de xuat thong tin! ";
        goto here;
    }
}
void xuatthuebaodangkisaunam2010(in4 thuebao[], int n)
{
    cout << "thue bao dang ki sau 2010: ";
    printf("%30s %30s %30s %30s %30s %30s\n", "Ten thue bao", "Ten chu thue bao", "NgaySinh", "Loai thue bao", "tgian noi mang", "tgian ngoai mang");
    for (int i = 0; i < n; i++)
    {                                                                                                // substrBack cat chuoi !
        string tmp = thuebao[i].date.substr(thuebao[i].date.length() - 4, thuebao[i].date.length()); // cat chuoi tu cuoi len dau o lay 4 ki tu !
        if (tmp.compare("2010") > 0)
            xuat1thuebao(thuebao[i]);
    }
}
void tinhcuocphithuebao(in4 thuebao[], int n)
{
    cout << "cuoc phi cua cac thue baothue bao! " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ". Thue bao:" << thuebao[i].mathuebao << " la: " << thuebao[i].timeNgoaiMang * 3000 + thuebao[i].timeNoiMang * 1500 << " dong" << endl;
    }
}
int soluongthuebaotratruoc(in4 thuebao[], int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (thuebao[i].loaiThueBao == 1)
            dem++;
    }
    return dem;
}
int main()
{
    int n = 0;
    cout << "Nhap vao so luong thue bao ";
    cin >> n;
    in4 ab[100];
    int luachon = 0;
    do
    {
        cout << "\t\tChuong trinh quan li thue bao dien thoai\n"
             << "1. Nhap thong tin cua cac thue bao.\n"
             << "2. Xuat thong tin cua cac thue bao.\n"
             << "3. Them mot thue bao cua cac thue bao.\n"
             << "4. Xap xep danh sach cac thue bao theo ma thue bao. \n"
             << "5. Tim thue bao theo ho ten chu thue bap.\n"
             << "6. Xuat cac thue bao theo loai. \n"
             << "7. Xuat thue bao dang ki sau nam 2010. \n"
             << "8. Tinh cuoc phi cua moi thue bao. \n"
             << "9. So luong thue bao tra truoc. \n"
             << "0. Thoat chuong trinh.!" << endl;
        cout << "Nhap lua chon: ";
        cin >> luachon;
        switch (luachon)
        {
        case 1:
            inputthuepaoS(ab, n);
            break;
        case 2:
            xuatThongTinCacThueBao(ab, n);
            break;
        case 3:
            them1biuKien(ab, n);
            break;
        case 4:
            sort(ab, n);
            break;
        case 5:
            timThueBao(ab, n);
            break;
            case 6:
            xuatthuebaotheoloai(ab,n) ; 
            break ; 
            case 7:
            xuatthuebaodangkisaunam2010(ab,n) ; 
            break ; 
            case 8:
            tinhcuocphithuebao(ab,n) ; 
            break ;  
            case 9:
            cout<<"So luong thue bao tra truoc: "<<soluongthuebaotratruoc(ab,n)<<endl;  
            break ;  
        }
    } while (luachon != 0);
}