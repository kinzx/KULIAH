#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur untuk data pasien
typedef struct
{
    char nama[50];
    char alamat[100];
    char nomor_telepon[15];
    char dokter[50];
    char riwayat_perawatan[100];
    char penyakit[50];
    char obat[50];
    float total_pembayaran;
    char metode_pembayaran[10];
    int member;         // 1 jika memiliki keanggotaan, 0 jika tidak
    int poin_loyalitas; // Poin loyalitas untuk member
} Pasien;

// Fungsi untuk menambah data pasien
void tambahPasien(Pasien pasien[], int *jumlah)
{
    printf("Masukkan nama pasien: ");
    scanf(" %[^]", pasien[*jumlah].nama);
    printf("Masukkan alamat pasien: ");
    scanf(" %[^]", pasien[*jumlah].alamat);
    printf("Masukkan nomor telepon pasien: ");
    scanf(" %[^]", pasien[*jumlah].nomor_telepon);
    printf("Masukkan dokter yang menangani: ");
    scanf(" %[^]", pasien[*jumlah].dokter);
    printf("Masukkan riwayat perawatan: ");
    scanf(" %[^]", pasien[*jumlah].riwayat_perawatan);
    printf("Masukkan penyakit (jika ada): ");
    scanf(" %[^]", pasien[*jumlah].penyakit);
    printf("Masukkan obat yang diberikan: ");
    scanf(" %[^]", pasien[*jumlah].obat);
    printf("Masukkan total pembayaran: ");
    scanf("%f", &pasien[*jumlah].total_pembayaran);

    // Validasi metode pembayaran
    do
    {
        printf("Masukkan metode pembayaran (QRIS/Bank/Cash): ");
        scanf(" %[^\n]", pasien[*jumlah].metode_pembayaran);
        if (strcmp(pasien[*jumlah].metode_pembayaran, "QRIS") != 0 &&
            strcmp(pasien[*jumlah].metode_pembayaran, "Bank") != 0 &&
            strcmp(pasien[*jumlah].metode_pembayaran, "Cash") != 0)
        {
            printf("Metode pembayaran tidak valid! Silakan coba lagi.\n");
        }
    } while (strcmp(pasien[*jumlah].metode_pembayaran, "QRIS") != 0 &&
             strcmp(pasien[*jumlah].metode_pembayaran, "Bank") != 0 &&
             strcmp(pasien[*jumlah].metode_pembayaran, "Cash") != 0);
    // Validasi keanggotaan
    do
    {
        printf("Apakah pasien memiliki keanggotaan? (1 untuk Ya, 0 untuk Tidak): ");
        scanf("%d", &pasien[*jumlah].member);
        if (pasien[*jumlah].member != 1 && pasien[*jumlah].member != 0)
        {
            printf("Input tidak valid! Masukkan 1 atau 0.\n");
        }
    } while (pasien[*jumlah].member != 1 && pasien[*jumlah].member != 0);

    pasien[*jumlah].poin_loyalitas = 0; // Inisialisasi poin loyalitas

    // Jika pasien adalah member, berikan diskon dan poin loyalitas
    if (pasien[*jumlah].member == 1)
    {
        printf("Member terdaftar! Anda mendapatkan diskon 10%% dan poin loyalitas.\n");
        pasien[*jumlah].total_pembayaran *= 0.9;                                          // Diskon 10%
        pasien[*jumlah].poin_loyalitas = (int)(pasien[*jumlah].total_pembayaran / 10000); // 1 poin untuk setiap 10.000
    }
    else
    {
        printf("Pasien bukan member.\n");
    }

    (*jumlah)++;
    printf("Data pasien berhasil ditambahkan.\n");
}

// Fungsi untuk menampilkan data pasien
void tampilkanPasien(Pasien pasien[], int jumlah)
{
    printf("Data Rekam Medis Pasien:\n");
    for (int i = 0; i < jumlah; i++)
    {
        printf("\nPasien %d:\n", i + 1);
        printf("Nama: %s\n", pasien[i].nama);
        printf("Alamat: %s\n", pasien[i].alamat);
        printf("Nomor Telepon: %s\n", pasien[i].nomor_telepon);
        printf("Dokter: %s\n", pasien[i].dokter);
        printf("Riwayat Perawatan: %s\n", pasien[i].riwayat_perawatan);
        printf("Penyakit: %s\n", pasien[i].penyakit);
        printf("Obat: %s\n", pasien[i].obat);
        printf("Total Pembayaran: %.2f\n", pasien[i].total_pembayaran);
        printf("Metode Pembayaran: %s\n", pasien[i].metode_pembayaran);
        printf("Keanggotaan: %s\n", pasien[i].member == 1 ? "Ya" : "Tidak");
        if (pasien[i].member == 1)
        {
            printf("Poin Loyalitas: %d\n", pasien[i].poin_loyalitas);
        }
    }
}

// Fungsi untuk menyimpan data ke file CSV
void simpanKeFile(Pasien pasien[], int jumlah)
{
    FILE *file = fopen("Rekam_Medis_Pasien.csv", "w");
    if (file == NULL)
    {
        printf("Gagal membuka file untuk menyimpan data.\n");
        return;
    }
    fprintf(file, "Nama,Alamat,Nomor Telepon,Dokter,Riwayat Perawatan,Penyakit,Obat,Total Pembayaran,Metode Pembayaran,Keanggotaan,Poin Loyalitas\n");
    for (int i = 0; i < jumlah; i++)
    {
        fprintf(file, "%s,%s,%s,%s,%s,%s,%s,%.2f,%s,%s,%d\n",
                pasien[i].nama, pasien[i].alamat, pasien[i].nomor_telepon,
                pasien[i].dokter, pasien[i].riwayat_perawatan, pasien[i].penyakit,
                pasien[i].obat, pasien[i].total_pembayaran, pasien[i].metode_pembayaran,
                pasien[i].member == 1 ? "Ya" : "Tidak", pasien[i].poin_loyalitas);
    }
    fclose(file);
    printf("Data berhasil disimpan ke file Rekam_Medis_Pasien.csv\n");
}

// Fungsi untuk mencatat riwayat kunjungan pasien
void catatRiwayatKunjungan(Pasien pasien[], int index)
{
    FILE *file = fopen("Riwayat_Kunjungan.csv", "a");
    if (file == NULL)
    {
        printf("Gagal membuka file untuk mencatat riwayat kunjungan.\n");
        return;
    }
    fprintf(file, "%s,%s,%.2f,%s\n",
            pasien[index].nama, pasien[index].dokter,
            pasien[index].total_pembayaran, pasien[index].metode_pembayaran);
    fclose(file);
    printf("Riwayat kunjungan berhasil dicatat.\n");
}

// Fungsi utama
int main()
{
    Pasien pasien[100];
    int jumlah = 0;
    int pilihan;

    do
    {
        printf("\n=== Dental Care Unisa ===\n");
        printf("1. Tambah Data Pasien\n");
        printf("2. Tampilkan Data Pasien\n");
        printf("3. Simpan Data ke File\n");
        printf("4. Catat Riwayat Kunjungan\n");
        printf("5. Keluar\n");
        printf("Masukkan pilihan Anda: ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            tambahPasien(pasien, &jumlah);
            break;
        case 2:
            tampilkanPasien(pasien, jumlah);
            break;
        case 3:
            simpanKeFile(pasien, jumlah);
            break;
        case 4:
            if (jumlah > 0)
            {
                int index;
                printf("Masukkan nomor pasien untuk mencatat riwayat kunjungan (1-%d): ", jumlah);
                scanf("%d", &index);
                if (index < 1 || index > jumlah)
                {
                    printf("Nomor pasien tidak valid!\n");
                }
                else
                {
                    catatRiwayatKunjungan(pasien, index - 1);
                }
            }
            else
            {
                printf("Tidak ada data pasien untuk dicatat.\n");
            }
            break;
        case 5:
            printf("Terima kasih telah menggunakan sistem Dental Care Unisa.\n");
            break;
        default:
            printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 5);

    return 0;
}
