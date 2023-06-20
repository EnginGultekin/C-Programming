#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512

void recover_jpeg(const char* input_file) {
    // Open the input file
    FILE* file = fopen(input_file, "rb");
    if (file == NULL) {
        printf("Error: Cannot open input file.\n");
        return;
    }

    unsigned char buffer[BLOCK_SIZE];
    int file_count = 0;
    FILE* output_file = NULL;

    // Scan for JPEG file signatures
    while (fread(buffer, sizeof(unsigned char), BLOCK_SIZE, file) == BLOCK_SIZE) {
        // Check for JPEG signature (start of a new JPEG file)
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) {
            // Close the previous output file
            if (output_file != NULL) {
                fclose(output_file);
            }

            // Create a new output file
            char output_filename[20];
            sprintf(output_filename, "%03i.jpg", file_count);
            output_file = fopen(output_filename, "wb");
            if (output_file == NULL) {
                printf("Error: Cannot create output file.\n");
                fclose(file);
                return;
            }

            file_count++;
        }

        // Write the buffer to the output file
        if (output_file != NULL) {
            fwrite(buffer, sizeof(unsigned char), BLOCK_SIZE, output_file);
        }
    }

    // Close the output file and input file
    if (output_file != NULL) {
        fclose(output_file);
    }
    fclose(file);

    printf("JPEG recovery complete. Total files recovered: %d\n", file_count);
}


int main(int argc, char *argv[])
{
    
     // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: copy infile outfile\n");
        return 1;
    }

    // remember filenames
    const char* input_file = argv[1];

    recover_jpeg(input_file);

    return 0;
}