#include <stdio.h>

int main()
{

    char nama[100];
    int umur;

    FILE *in = fopen("text.txt", "r");

    if (!in)
    {
        printf("Error opening file");
    }
    else
    {
        while (!feof(in))
        {
            fscanf(in, "%[^#]#%d\n", &nama, &umur);
            fflush(stdin);
            printf("%s %d\n", nama, umur);
        }
        fclose(in);
    }
    getchar();
    return 0;
}