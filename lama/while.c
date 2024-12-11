#include <stdio.h>

int main()
{
    char *data[15] = {
        "Nama Panjang            : Kinar aurasae",
        "Nama Panggilan          : Kinar",
        "Nomor HP                : 089522295080",
        "NIM                     : 2411501025",
        "Tempat, Tanggal Lahir   : Kudus 9 Desember 2005",
        "Umur                    : 19",
        "Berat badan             : 50",
        "Tinggi badan            : 154",
        "Asal                    : Kudu",
        "Tempat Tinggal          : Batul",
        "Hobi                    : Main game dan menggambar",
        "Asal Sekolah            : SMK MUH 1 YK",
        "Makanan kesukaan        : Mie",
        "Warna kesukaan          : Hitam & putih",
        "Prodi                   : TI"
    };
    int j = 0;

    while (j < 15 ) {
    printf("\n--- Perkenalan Diri ke-%d ---\n", j + 1);
    int i =0;
    while (i < 15)
    {
        printf("%s\n", data[i]);
        i++;
    }

    j++;
    }

    // for (int j = 0; j < 15; j++) {
    //     printf("\n--- Perkenalan Diri ke-%d ---\n", j + 1);
    //     for (int i = 0; i < 15; i++) {
    //         printf("%s\n", data[i]);
    //     }
    // }

    return 0;
}
