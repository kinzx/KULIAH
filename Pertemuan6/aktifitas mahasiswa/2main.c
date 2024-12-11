#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *filePointer;

    char dataToBeWritten[50] = "Dasar Pemprograman Praktikum Semester 1";

    filePointer = fopen("file-test.c", "w");

    if (filePointer == NULL)
    {
        printf("File-test.c file tidak dapat dibuka.\n");
    }
    else
    {
        printf("File sudah dibuka dan dapat dioperasikan.\n");
        if (strlen(dataToBeWritten) > 0)
        {
            fputs(dataToBeWritten, filePointer);
            fputs("\n", filePointer);
        }

        fclose(filePointer);

        filePointer = fopen("file-test.c", "r");

        if (filePointer == NULL)
        {
            printf("File-test.c file tidak dapat dibuka.\n");
        }
        else
        {
            printf("file sudah dibuka dan dapat dioperasikan.\n");

            while (fgets(dataToBeWritten, 50, filePointer) != NULL)
            {
                printf("isi file-test.c adalah %s", dataToBeWritten);
            }

            fclose(filePointer);

            printf("Berhasil membaca data pada file file-test.c\n");
            printf("file sekarang di tutup.");
        }
    }
}