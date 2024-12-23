#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Struktur untuk posisi pemain
typedef struct {
    int x, y;
} Position;

// Fungsi untuk menyimpan permainan ke file
void saveGame(Position doctor, Position patient, int size) {
    FILE *file = fopen("savegame.txt", "w");
    if (file == NULL) {
        printf("Gagal menyimpan permainan!\n");
        return;
    }
    fprintf(file, "%d %d %d %d %d\n", doctor.x, doctor.y, patient.x, patient.y, size);
    fclose(file);
    printf("Permainan berhasil disimpan.\n");
}

// Fungsi untuk memuat permainan dari file
int loadGame(Position *doctor, Position *patient, int *size) {
    FILE *file = fopen("savegame.txt", "r");
    if (file == NULL) {
        printf("Tidak ada permainan yang disimpan.\n");
        return 0;
    }
    fscanf(file, "%d %d %d %d %d", &doctor->x, &doctor->y, &patient->x, &patient->y, size);
    fclose(file);
    printf("Permainan berhasil dimuat.\n");
    return 1;
}

// Fungsi untuk mencetak arena
void printArena(Position doctor, Position patient, int size) {
    system("clear || cls");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == doctor.y && j == doctor.x)
                printf("D ");
            else if (i == patient.y && j == patient.x)
                printf("P ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

// Fungsi utama
int main() {
    Position doctor, patient;
    int size;
    char choice;

    printf("Ingin memuat permainan yang disimpan? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        if (!loadGame(&doctor, &patient, &size)) {
            printf("Mulai permainan baru.\n");
            choice = 'n';
        }
    }

    if (choice == 'n' || choice == 'N') {
        printf("Masukkan ukuran arena (NxN): ");
        scanf("%d", &size);

        srand(time(NULL));
        doctor.x = rand() % size;
        doctor.y = rand() % size;
        patient.x = rand() % size;
        patient.y = rand() % size;
    }

    while (1) {
        printArena(doctor, patient, size);

        // Periksa apakah dokter menangkap pasien
        if (doctor.x == patient.x && doctor.y == patient.y) {
            printf("Dokter menangkap pasien! Permainan selesai.\n");
            break;
        }

        printf("Gerakan dokter (w/a/s/d), atau tekan q untuk keluar: ");
        char move;
        scanf(" %c", &move);

        if (move == 'q') {
            saveGame(doctor, patient, size);
            break;
        }

        // Gerakan dokter
        if (move == 'w' && doctor.y > 0) doctor.y--;
        if (move == 'a' && doctor.x > 0) doctor.x--;
        if (move == 's' && doctor.y < size - 1) doctor.y++;
        if (move == 'd' && doctor.x < size - 1) doctor.x++;

        // Gerakan pasien (acak)
        int direction = rand() % 4;
        if (direction == 0 && patient.y > 0) patient.y--;
        if (direction == 1 && patient.x > 0) patient.x--;
        if (direction == 2 && patient.y < size - 1) patient.y++;
        if (direction == 3 && patient.x < size - 1) patient.x++;
    }

    return 0;
}
