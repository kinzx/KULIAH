#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr;

    fptr = fopen("file.txt", "w");

    if (fptr == NULL)
    {
        printf("Could not open file \n");
        exit(0);
    }
    else
    {
        printf("File opened successfully \n");
    }

    return 0;
}