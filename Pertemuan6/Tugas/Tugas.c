#include <stdio.h>
#include <string.h>

int main()
{

    FILE *fp = fopen("rekam_medis.csv", "a+");
    char nama_pasien[50];
    char diagnosa[100];
    int umur;
    char tanggal[15];

    if (!fp)
    {

        printf("Tidak dapat membuka file\n");
        return 0;
    }

    printf("Masukkan Nama Pasien: ");
    scanf(" %[^\n]", nama_pasien);
    printf("Masukkan Umur Pasien: ");
    scanf("%d", &umur);
    printf("Masukkan Diagnosa: ");
    scanf(" %[^\n]", diagnosa);
    printf("Masukkan Tanggal (dd/mm/yyyy): ");
    scanf(" %[^\n]", tanggal);

    fprintf(fp, "%s, %d, %s, %s\n", nama_pasien, umur, diagnosa, tanggal);
    printf("Data Rekam Medis telah ditambahkan\n");
    fclose(fp);

    printf("\n\n");

    FILE *fpp = fopen("rekam_medis.csv", "r");
    if (!fpp)
    {
        printf("Tidak dapat membuka file\n");
        return 0;
    }
    else
    {
        char buffer[1024];
        int row = 0;
        int column = 0;

        printf("Data Rekam Medis Rumah Sakit Aisyiyyah:\n\n");
        while (fgets(buffer, 1024, fpp))
        {
            column = 0;
            row++;

            if (row == 0)
                continue;

                        char *value = strtok(buffer, ", ");

            while (value)
            {
                if (column == 0)
                {
                    printf("Nama Pasien: %s", value);
                }
                else if (column == 1)
                {
                    printf("\tUmur: %s", value);
                }
                else if (column == 2)
                {
                    printf("\tDiagnosa: %s", value);
                }
                else if (column == 3)
                {
                    printf("\tTanggal: %s", value);
                }

                value = strtok(NULL, ", ");
                column++;
            }
            printf("\n");
        }
    }

    fclose(fpp);

    return 0;
}
