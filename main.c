#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void print_buffer(const char *label, const char *buffer, size_t size) {
    printf("%s: ", label);
    for (size_t i = 0; i < size; i++) {
        printf("%02x ", buffer[i]);
    }
    printf("\n");
}

int dma_transfer(char *src, char *dst, size_t size) {
    // Simulate DMA transfer with memcpy
    memcpy(dst, src, size);
    return 0; // Return 0 to indicate success
}

int main() {
    // Allocate source and destination buffers
    char *src_buffer = (char *)malloc(BUFFER_SIZE);
    char *dst_buffer = (char *)malloc(BUFFER_SIZE);
    if (!src_buffer || !dst_buffer) {
        perror("Failed to allocate buffers");
        return EXIT_FAILURE;
    }

    // Initialize source buffer with some data
    memset(src_buffer, 0xAB, BUFFER_SIZE);
    memset(dst_buffer, 0x00, BUFFER_SIZE);

    // Print buffers before DMA transfer
    print_buffer("Source buffer before DMA", src_buffer, BUFFER_SIZE);
    print_buffer("Destination buffer before DMA", dst_buffer, BUFFER_SIZE);

    // Perform DMA transfer
    if (dma_transfer(src_buffer, dst_buffer, BUFFER_SIZE) != 0) {
        fprintf(stderr, "DMA transfer failed\n");
        free(src_buffer);
        free(dst_buffer);
        return EXIT_FAILURE;
    }

    // Print buffers after DMA transfer
    print_buffer("Source buffer after DMA", src_buffer, BUFFER_SIZE);
    print_buffer("Destination buffer after DMA", dst_buffer, BUFFER_SIZE);

    // Clean up
    free(src_buffer);
    free(dst_buffer);

    return EXIT_SUCCESS;
}
