#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int length, i;

    printf("Masukkan sebuah kalimat: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    length = strlen(str);
    printf("Panjang kalimat: %d karakter\n", length);

    for (i = 0; i < length; i++)
    {
        str[i] = toupper(str[i]);
    }
    printf("Kalimat dalam huruf kapital: ");
    fputs(str, stdout);
    printf("\n");

    return 0;
}
