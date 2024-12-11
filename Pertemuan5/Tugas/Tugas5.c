#include <stdio.h>

int main() {
    // array
    char data[5] = {'a', 'b', 'c', 'd', 'e'};

    // Menampilkan array
    printf("Array :\n");
    for (int i = 0; i < 5; i++) {
        printf("Elemen ke-%d: %c\n", i + 1, data[i]);
    }

    return 0;
}
