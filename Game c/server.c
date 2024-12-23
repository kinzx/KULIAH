#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_fd, client_fd;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char* message = "Hello, World!";

    // Buat socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket gagal");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("bind gagal");
        exit(EXIT_FAILURE);
    }

    // Dengarkan koneksi
    if (listen(server_fd, 3) < 0) {
        perror("listen gagal");
        exit(EXIT_FAILURE);
    }

    printf("Server berjalan di port %d...\n", PORT);

    while (1) {
        // Terima koneksi
        client_fd = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
        if (client_fd < 0) {
            perror("accept gagal");
            continue;
        }

        // Terima permintaan
        read(client_fd, buffer, BUFFER_SIZE);
        printf("Permintaan diterima: %s\n", buffer);

        // Kirim respons
        send(client_fd, message, strlen(message), 0);
        printf("Respons dikirim: %s\n", message);

        // Tutup koneksi
        close(client_fd);
    }

    return 0;
}