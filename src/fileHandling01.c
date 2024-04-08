#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* srcFile = fopen("./fileHandling/oshin_000.txt", "w");
    if(!srcFile) { exit(EXIT_FAILURE); }

    char cBuffer = 0;
    
    while ((cBuffer = getchar()) != '\n' ) {
        fputc(cBuffer, srcFile);
    }
    cBuffer = 0;
    fclose(srcFile);

    srcFile = fopen("./fileHandling/oshin_000.txt", "r");
    if(!srcFile) { exit(EXIT_FAILURE); }

    FILE* destFile = fopen("./fileHandling/oshin_000_cpy.txt", "w");
    if(!destFile) { exit(EXIT_FAILURE); }

    printf("\nWriting into another file:\n");
    cBuffer = fgetc(srcFile);
    while( cBuffer != EOF ) {
        switch (cBuffer)
        {
        case 'a':
        case 's':
        case 't':
        case 'r':
        case 'd':
            break;
        default:
            fputc(cBuffer, destFile);
            putc(cBuffer, stdout);
            break;
        }
        cBuffer = fgetc(srcFile);
    }

    fclose(destFile);
    fclose(srcFile);

    printf("\nName:Oshin Pant\n Roll no:19\n Lab no:1");
    getc(stdin);
    return 0;
}