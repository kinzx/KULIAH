#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int angkaRahasia, tebakan, peluang = 5;

    srand(time(0)); // Inisialisasi seed untuk angka acak
    angkaRahasia = rand() % 100 + 1;

    printf("Tebak angka antara 1-100 | Anda memiliki %d peluang.\n", peluang);

    for (int i = 0; i < peluang; i++)
    {
        printf("-------------------------------------\n");
        printf("Masukkan tebakan Anda: ");
        scanf("%d", &tebakan);

        if (tebakan == angkaRahasia)
        {
            printf("-------------------------------------\n");
            printf("Selamat! Anda menebak dengan benar.\n");
            printf("-------------------------------------\n");
            return 0;
        }
        else if (tebakan < angkaRahasia)
        {
            printf("-------------------------------------\n");
            printf("Terlalu kecil!\n");
        }
        else
        {
            printf("-------------------------------------\n");
            printf("Terlalu besar!\n");
        }
    }

    printf("-------------------------------------\n");
    printf("Maaf, Anda kehabisan peluang. Angka yang benar adalah %d.\n", angkaRahasia);
    return 0;
}