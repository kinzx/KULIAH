#include <stdio.h>

void main()
{
    printf("--- Program Antrian Rumah Sakit UNISA ---\n");

    char no_antrian[5] = {'A', 'B', 'C', 'D', 'E'};

    char *ptr_current = &no_antrian;

    printf("Daftar Antrian: ");
    for (int i = 0; i < 5; i++)
    {
        printf("[%c] ", no_antrian[i]);
    }
    printf("\n");
    for (int i = 0; i < 5; i++)
    {
        printf("\n====================================\n");
        printf(">>> Nomor Antrian Saat Ini: %c <<<\n", *ptr_current);
        printf("====================================\n");
        printf("Pelanggan dengan nomor antrian %c, silakan menuju ke loket.\n", *ptr_current);
        printf("------- Tekan Enter Next ------------");
        getchar();
        ptr_current++;
    }

    printf("\n====================================\n");
    printf("Semua antrian telah selesai dilayani.\n");
    printf("Terima kasih telah mengunjungi Rumah Sakit UNISA.\n");
    printf("====================================\n");
}