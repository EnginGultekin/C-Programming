// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: copy infile outfile\n");
        return 1;
    }


    // remember filenames
    float f = atof(argv[1]);
    char *infile = argv[2];
    char *outfile = argv[3];


    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);


    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    
      // check n value
     if (f >= 1 && f <= 100) {
    int n = f; 
    // infile padding calculation
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // update image height and width in bitmapinfoheader
    bi.biWidth *= n;
    bi.biHeight *= n;

    // determine padding for scanlines
    int newPadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // update image size in both headers
    bi.biSizeImage = ((sizeof(RGBTRIPLE) * bi.biWidth) + newPadding) * abs(bi.biHeight);
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight / n); i < biHeight; i++)
    {
        // iterate over rows n - 1 times
        for (int j = 0; j < (n - 1); j++)
        {
            // iterate over pixels in scanline
            for (int k = 0, biWidth = bi.biWidth / n; k < biWidth; k++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                for (int l = 0; l < n; l++)
                {
                    // write RGB triple to outfile n times
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }

            // add newPadding
            for (int m = 0; m < newPadding; m++)
            {
                fputc(0x00, outptr);
            }

            // return infile cursor back to start of line
            fseek(inptr, -(bi.biWidth / n) * sizeof(RGBTRIPLE), SEEK_CUR);
        }

        // iterate over pixels in scanline
        for (int k = 0, biWidth = bi.biWidth / n; k < biWidth; k++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            for (int l = 0; l < n; l++)
            {
                // write RGB triple to outfile n times
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            }
        }

        // add newPadding
        for (int m = 0; m < newPadding; m++)
        {
            fputc(0x00, outptr);
        }

        // skip over original padding, if any
        fseek(inptr, padding, SEEK_CUR);
    }



    }
     else if (f > 0.0 && f < 1.0) {
         BITMAPFILEHEADER bf_resize = bf;
    BITMAPINFOHEADER bi_resize = bi;
    bi_resize.biWidth = bi.biWidth * f;
    bi_resize.biHeight = fabs(bi.biHeight * f);
    int padding = bi.biWidth % 4;       // you can simplify the calculation
    int padding_resize = bi_resize.biWidth % 4;
    bi_resize.biSizeImage = (bi_resize.biWidth * sizeof(RGBTRIPLE) + padding_resize) * bi_resize.biHeight;
    bf_resize.bfSize = bi_resize.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

   // temporary storage
    RGBTRIPLE triple;

    // allocate mamory for the rgb triplets of the original (input) image
    RGBTRIPLE *pix = malloc(sizeof(RGBTRIPLE) * bi.biWidth * abs(bi.biHeight));
    if (pix == NULL) {
        fprintf(stderr, "malloc failed.\n");
        return 5;
    }


    // read the entire pixels of the original image and store into the memory
    for (int i = 0; i < abs(bi.biHeight); i++) {
        for (int j = 0; j < bi.biWidth; j++) {
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
            pix[i * bi.biWidth + j] = triple;
        }
        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);
    }

    // write outfile's header
    fwrite(&bf_resize, sizeof(BITMAPFILEHEADER), 1, outptr);
    fwrite(&bi_resize, sizeof(BITMAPINFOHEADER), 1, outptr);

    // write the pixels of destination (resized) image
    for (int i = 0; i < bi_resize.biHeight; i++) {
        for (int j = 0; j < bi_resize.biWidth; j++) {
            // calculate the corresponding coorinates in the original image
            int m = (i / f + 0.5);              // +0.5 for rounding
            if (m > abs(bi.biHeight) - 1) {          // limit the value
                m = bi.biHeight - 1;
            }
            int n = (j / f + 0.5);
            if (n > (bi.biWidth) - 1) {
                n = (bi.biWidth) - 1;
            }
            // pick the pixel value at the coordinate
            triple = pix[m * bi.biWidth + n];
            // write RGB triplet to outfile
            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
        }
        // padding for the output image, if any
        for (int j = 0; j < padding_resize; j++) {
            fputc(0x00, outptr);
        }
    }
    free(pix);
      
    }
    else {
        fprintf(stderr, "f, the resize factor, must be between 0 and 1.\n");
        return 1; 
    }


   
    fclose(inptr);
    fclose(outptr);

    return 0;
}