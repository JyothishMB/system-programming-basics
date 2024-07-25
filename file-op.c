#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    const char *filename = "example.txt";

    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if(fd==-1) {
        perror("Error opening file.");
        return 1;
    }

    const char *data = "Hello World!\n";

    ssize_t bytes_written = write(fd, data, strlen(data));

    if(bytes_written == -1) {
        perror("Error writing to file.");
        return 1;
    }

    if(close(fd) == -1) {
        perror("Error closing file");
        return 1;
    }

    printf("File opened, written and closed successfully.\n");
    return 0;
}