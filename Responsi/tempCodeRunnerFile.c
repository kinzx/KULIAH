#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur untuk data pasien
typedef struct {
    char nama[50];
    char alamat[100];
    char nomor_telepon[15];
    char dokter[50];
    char riwayat_perawatan[100];
    char penyakit[50];
    char obat[50];
    float total_pembayaran;
    char metode_pembayaran[10];
} Pasien;

// Fungsi untuk menambah data pasien
void tambahPasien(Pasien pasien[], int *jumlah) {
    printf("Masukkan nama pasien: ");
    scanf(" %[^\n]", pasien[*jumlah].nama);
    printf("Masukkan alamat pasien: ");
    scanf(" %[^\n]", pasien[*jumlah].alamat);
    printf("Masukkan nomor telepon pasien: ");
    scanf(" %[^\n]", pasien[*jumlah].nomor_telepon);
    printf("Masukkan dokter yang menangani: ");
    scanf(" %[^\n]", pasien[*jumlah].dokter);
    printf("Masukkan riwayat perawatan: ");
    scanf(" %[^\n]", pasien[*jumlah].riwayat_perawatan);
    printf("Masukkan penyakit (jika ada): ");
    scanf(" %[^\n]", pasien[*jumlah].penyakit);
    printf("Masukkan obat yang diberikan: ");
    scanf(" %[^\n]", pasien[*jumlah].obat);
    printf("Masukkan total pembayaran: ");
    scanf("%f", &pasien[*jumlah].total_pembayaran);
    printf("Masukkan metode pembayaran (QRIS/Bank/Cash): ");
    scanf(" %[^\n]", pasien[*jumlah].metode_pembayaran);
    (*jumlah)++;
    printf("Data pasien berhasil ditambahkan.\n");
}

// Fungsi untuk menampilkan data pasien
void tampilkanPasien(Pasien pasien[], int jumlah) {
    printf("Data Rekam Medis Pasien:\n");
    for (int i = 0; i < jumlah; i++) {
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
    }
}

// Fungsi untuk menyimpan data ke file CSV
void simpanKeFile(Pasien pasien[], int jumlah) {
    FILE *file = fopen("Rekam_Medis_Pasien.csv", "w");
    if (file == NULL) {
        printf("Gagal membuka file untuk menyimpan data.\n");
        return;
    }
    fprintf(file, "Nama,Alamat,Nomor Telepon,Dokter,Riwayat Perawatan,Penyakit,Obat,Total Pembayaran,Metode Pembayaran\n");
    for (int i = 0; i < jumlah; i++) {
        fprintf(file, "%s,%s,%s,%s,%s,%s,%s,%.2f,%s\n",
                pasien[i].nama, pasien[i].alamat, pasien[i].nomor_telepon,
                pasien[i].dokter, pasien[i].riwayat_perawatan, pasien[i].penyakit,
                pasien[i].obat, pasien[i].total_pembayaran, pasien[i].metode_pembayaran);
    }
    fclose(file);
    printf("Data berhasil disimpan ke file Rekam_Medis_Pasien.csv\n");
}

// Fungsi untuk menghapus data pasien
void hapusPasien(Pasien pasien[], int *jumlah) {
    int index;
    printf("Masukkan nomor pasien yang ingin dihapus (1-%d): ", *jumlah);
    scanf("%d", &index);
    if (index < 1 || index > *jumlah) {
        printf("Nomor pasien tidak valid.\n");
        return;
    }
    for (int i = index - 1; i < (*jumlah) - 1; i++) {
        pasien[i] = pasien[i + 1];
    }
    (*jumlah)--;
    printf("Data pasien berhasil dihapus.\n");
}

// Fungsi utama
int main() {
    Pasien pasien[100];
    int jumlah = 0;
    int pilihan;

    do {
        printf("\n=== Dental Care Unisa ===\n");
        printf("1. Tambah Data Pasien\n");
        printf("2. Tampilkan Data Pasien\n");
        printf("3. Simpan Data ke File\n");
        printf("4. Hapus Data Pasien\n");
        printf("5. Keluar\n");
        printf("Masukkan pilihan Anda: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
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
                hapusPasien(pasien, &jumlah);
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
