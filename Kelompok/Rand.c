
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int angkaAcak;

    angkaAcak = rand() % 100; // Angka acak antara 0-99
    printf("Angka acak yang dihasilkan: %d\n", angkaAcak);

    return 0;
}
