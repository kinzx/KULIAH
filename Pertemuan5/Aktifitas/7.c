#include <stdio.h>

void main()
{
    printf("## Program Antrian CS ##\n");

    char no_antrian[5] = {'A', 'B', 'C', 'D', 'E'};

    char *ptr_current = &no_antrian;

    for (int i = 0; i < 5; i++)
    {
        printf("Pelanggan dengan nomer antrian %c seilahkan ke loket!\n", *ptr_current);
        printf("Saat ini CS sedang melayani: %c\n", *ptr_current);
        printf("------- Tekan Enter Next ------------");
        getchar();
        ptr_current++;
    }

    printf(" Selesai");
}