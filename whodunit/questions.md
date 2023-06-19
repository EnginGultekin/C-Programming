# Questions

## What's `stdint.h`?

#### The <stdint.h> header declares sets of integer types having specified widths, and defines corresponding sets of macros. It also defines macros that specify limits of integer types corresponding to types defined in other standard headers.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

###### The C language defines several integer data types: integer, short integer, long integer, and character, all in both signed and unsigned varieties. The GNU C compiler extends the language to contain long long integers as well.

###### The C integer types were intended to allow code to be portable among machines with different inherent data sizes (word sizes), so each type may have different ranges on different machines. 
###### The problem with this is that a program often needs to be written for a particular range of integers, and sometimes must be written for a particular size of storage, regardless of what machine the program runs on.

###### These typedefs are in stdint.h.

###### If you require that an integer be represented in exactly N bits, use one of the following types, with the obvious mapping to bit size and signedness:

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

#### `BYTE` = 8 bits = 1 bytes
#### `WORD` = 2 BYTE = 16 bits
#### `DWORD` = 2 WORDs = 4 bytes = 32 bits
#### `LONG` = 8 bytes or (4bytes for 32 bit OS)  

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

### `0x`

## What's the difference between `bfSize` and `biSize`?

##### bfSize = biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER)
###### bisize is BITMAPINFOHEADER

## What does it mean if `biHeight` is negative?

##### Height of a bmp image can be negative- if the image is stored top to bottom. When figuring out the size of the image, negative doesn't make sense, so it should be the absolute value of the height.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

##### In the BITMAPINFOHEADER structure, the field that specifies the BMP's color depth, or bits per pixel (BPP), is called `biBitCount`. This field represents the number of bits used to represent each pixel in the bitmap image.

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

##### argv[1] and argv[2]  could not be opened. There are a few reasons why this could happen:

## Why is the third argument to `fread` always `1` in our code? (For example, see lines 40, 44, and 75.)

#### size_t fread(void *ptr, size_t size, size_t count, FILE *stream);

###### In this line, *ptr is the address of the BITMAPFILEHEADER structure where the data will be read into. sizeof(BITMAPFILEHEADER) represents the size of the BITMAPFILEHEADER structure in bytes, which specifies the size of a single element to be read. The count is set to 1, indicating that only one BITMAPFILEHEADER element should be read from the file.

###### Similarly, in lines 40, 44 and 75, the fread function is used to read a single BITMAPINFOHEADER element and a single RGBTRIPLE element, respectively, from the file.

###### In summary, the count of 1 in the fread calls in the provided code indicates that the intention is to read a single element of a specific size from the file.

## What value does line 63 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

### 3

## What does `fseek` do?

###### The fseek function  is used to set the file position indicator for a given file stream. It allows you to move the position within a file, enabling reading from or writing to specific locations.

## What is `SEEK_CUR`?

###### `SEEK_SET`: The offset is relative to the beginning of the file.
###### `SEEK_CUR`: The offset is relative to the current position indicator.
###### `SEEK_END`: The offset is relative to the end of the file.


###### Using SEEK_CUR allows you to perform relative seeking within a file without needing to know the absolute position.
