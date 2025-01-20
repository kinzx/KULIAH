#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>

const int lebar = 20;
const int tinggi = 10;
const int jumlah_rintangan = 5;

// Struktur pasien
typedef struct {
    int x, y;
} Pasien;

// Struktur perawat
typedef struct {
    int x, y;
} Perawat;

// Struktur rintangan
typedef struct {
    int x, y;
} Rintangan;

// Fungsi untuk menggambar layar
void gambarLayar(Pasien pasien, Perawat perawat, Rintangan rintangan[], int jumlah_rintangan) {
    for (int i = 0; i < tinggi; i++) {
        for (int j = 0; j < lebar; j++) {
            if (i == pasien.y && j == pasien.x) {
                printf("P"); // Pasien
            } else if (i == perawat.y && j == perawat.x) {
                printf("R"); // Perawat
            } else {
                bool isRintangan = false;
                for (int k = 0; k < jumlah_rintangan; k++) {
                    if (i == rintangan[k].y && j == rintangan[k].x) {
                        printf("X"); // Rintangan
                        isRintangan = true;
                        break;
                    }
                }
                if (!isRintangan) {
                    printf(" "); // Spasi
                }
            }
        }
        printf("\n");
    }
}

// Fungsi untuk menggerakkan pasien
void gerakkanPasien(Pasien *pasien, char arah) {
    switch (arah) {
        case 'w':
            pasien->y--;
            break;
        case 'a':
            pasien->x--;
            break;
        case 's':
            pasien->y++;
            break;
        case 'd':
            pasien->x++;
            break;
    }
}

// Fungsi untuk memeriksa tabrakan
bool tabrakan(Pasien pasien, Rintangan rintangan[], int jumlah_rintangan) {
    for (int i = 0; i < jumlah_rintangan; i++) {
        if (pasien.x == rintangan[i].x && pasien.y == rintangan[i].y) {
            return true;
        }
    }
    return false;
}

// Fungsi untuk memeriksa kemenangan
bool kemenangan(Pasien pasien, Perawat perawat) {
    return pasien.x == perawat.x && pasien.y == perawat.y;
}

int main() {
    srand(time(0)); // Inisialisasi seed acak

    Pasien pasien = {1, 1};
    Perawat perawat = {lebar - 2, tinggi - 2};
    Rintangan rintangan[jumlah_rintangan];

    // Inisialisasi rintangan
    for (int i = 0; i < jumlah_rintangan; i++) {
        rintangan[i].x = rand() % (lebar - 2) + 1;
        rintangan[i].y = rand() % (tinggi - 2) + 1;
    }

    char arah;
    while (1) {
        system("clear"); // Membersihkan layar
        gambarLayar(pasien, perawat, rintangan, jumlah_rintangan);

        // Input arah
        printf("Masukkan arah (w/a/s/d): ");
        scanf(" %c", &arah);

        // Gerakkan pasien
        gerakkanPasien(&pasien, arah);

        // Periksa tabrakan
        if (tabrakan(pasien, rintangan, jumlah_rintangan)) {
            printf("Pasien menabrak rintangan! Game over.\n");
            break;
        }

        // Periksa kemenangan
        if (kemenangan(pasien, perawat)) {
            printf("Pasien mencapai perawat! Selamat!\n");
            break;
        }

        // Tunda permainan
    }

    return 0;
}
