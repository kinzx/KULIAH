#include <stdio.h>
#include <stdlib.h>

struct threeNum
{
    int n1, n2, n3;
};

int main()
{
    int n;

    struct threeNum num;

    FILE *fptr;
    if ((fptr = fopen("program.bin", "wb")) == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    int flag = 0;
    // mengembalikan nilai pointer pada file (menulis data).
    for (n = 1; n < 5; ++n)
    {
        num.n1 = n;
        num.n2 = 5 * n;
        num.n3 = 5 * n + 1;
        // menulis data pada file binary
        flag = fwrite(&num, sizeof(struct threeNum), 1, fptr);
    }
    // melakukan cek jika data sudah di tulis pada file binary
    if (!flag)
    {
        printf("Write Operation Failure");
    }
    else
    {
        printf("Write Operation Successful");
    }
    fclose(fptr); // menutup file

    printf("\n\n");

    if ((fptr = fopen("program.bin", "rb")) == NULL) // membuka dan membaca file
    {
        printf("Error! opening file");
        // melakukan cek file,
        // jika file biner tidak terbaca program berhenti.
        exit(1);
    }

    // mengembalikan nilai pointer pada file (menampilkan data).
    for (n = 1; n < 5; ++n)
    {
        // membaca data file perbaris
        fread(&num, sizeof(struct threeNum), 1, fptr);
        // menampilkan data file yang sudah dibaca perbaris
        printf("n1: %d\tn2: %d\tn3: %d\n", num.n1, num.n2, num.n3);
    }
    fclose(fptr); // menutup file

    return 0;
}
