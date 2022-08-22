#include <stdio.h>
int main()
{
    char ten[40];
    printf("nhap ten: ");
    gets(ten);
    strlwr(ten);
    ten[0] = ten[0] - 32;
    int i;
    for (i = 1; i < strlen(ten); i++)
    {
        if (ten[i - 1] == 32)
            ten[i] -= 32;
    }
    printf("\n%s", ten);
}
