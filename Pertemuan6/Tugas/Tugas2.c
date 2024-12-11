#include <stdio.h>

int main()
{
    FILE *file;
    char nama[50], diagnosa[100], tanggal[15];
    int umur;

    file = fopen("rekam_medis.csv", "a+");
    if (!file)
    {
        printf("Gagal membuka file rekam_medis.csv!\n");
        return 1;
    }

    // Input data pasien
    printf("Masukkan Nama Pasien: ");
    fgets(nama, sizeof(nama), stdin);
    printf("Masukkan Umur Pasien: ");
    scanf("%d", &umur);
    getchar();
    printf("Masukkan Diagnosa: ");
    fgets(diagnosa, sizeof(diagnosa), stdin);
    printf("Masukkan Tanggal (dd/mm/yyyy): ");
    fgets(tanggal, sizeof(tanggal), stdin);

    fprintf(file, "%s,%d,%s,%s", nama, umur, diagnosa, tanggal);
    fclose(file);

    printf("Data berhasil disimpan!\n");

    file = fopen("rekam_medis.csv", "r");
    if (!file)
    {
        printf("Gagal membuka file rekam_medis.csv untuk membaca!\n");
        return 1;
    }

    printf("\n--- Data Rekam Medis ---\n");
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file))
    {
        printf("%s", buffer);
    }
    fclose(file);

    return 0;
}
