
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char harga_str[20];
    int jumlah;
    double harga, total;

    printf("Masukkan harga barang (dalam string): ");
    scanf("%s", harga_str);

    printf("Masukkan jumlah barang: ");
    scanf("%d", &jumlah);

    // Mengonversi string harga menjadi bilangan floating-point
    harga = atof(harga_str);

    // Menghitung total harga
    total = harga * jumlah;

    printf("Total harga: %.2f\n", total);

    return 0;
}
