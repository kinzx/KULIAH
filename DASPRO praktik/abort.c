#include <stdio.h>
#include <stdlib.h>

int main()
{
    int input;

    printf("Masukkan angka positif: ");
    scanf("%d", &input);

    if (input < 0)
    {
        printf("Error: Angka yang dimasukkan negatif!\n");
        printf("Program dihentikan secara paksa.\n");
        abort();
    }

    printf("Angka yang Anda masukkan adalah: %d\n", input);
    return 0;
}