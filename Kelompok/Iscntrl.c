#include <stdio.h>
#include <ctype.h>

int main() {
    char c = '\n'; // Karakter yang ingin dicek

    if (iscntrl(c)) {
        printf("Karakter adalah karakter kontrol.\n");
    } else {
        printf("Karakter bukan karakter kontrol.\n");
    }

    return 0;
}