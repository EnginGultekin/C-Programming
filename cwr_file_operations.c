#include <cs50.h>
#include <string.h>
#include <stdio.h>

void writer_file();
void data_file();

int main(void)
{
    writer_file();
    data_file();

    return 0;
}

void writer_file(){
    FILE *fp;

    char str[] = "Created by LUGAN HAN";

    // "w" defines "writing mode"
    fp = fopen("writer.text", "w"); 
    for (int i = 0, len = strlen(str); i < len; i++) {
        /* write to file using fputc() function */
        fputc(str[i], fp);
    }
    fclose(fp);
}

void data_file(){
    FILE * fp;

    // "w+" defines for reading and writing, overwriting a file"
    fp = fopen("data.txt", "w+");
    fputs("I am Lugan Han\n", fp);
    fputs("My country is in bad shape. I don't know what do do\n", fp);
    fputs("Maybe you can help me ?\n", fp);
    
    fclose(fp);

    // "r" 	defines "reading mode"
    fp = fopen("data.txt", "r");
    char c;

    while ((c = getc(fp)) != EOF) printf("%c", c);
    fclose(fp);
}
