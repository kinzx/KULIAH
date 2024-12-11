#include <stdio.h>

int main()
{
    char nama[100];
    int umur;

    printf("Masukan nama : ");
    scanf("%[^\n]", &nama);
    fflush(stdin);
    printf("Masukan umur : ");
    scanf("%d", &umur);
    fflush(stdin);

    FILE *out=fopen("text.txt", "w");

    fprintf(out, "%s#%d\n", nama,umur);

    fclose(out);
    return 0;
}