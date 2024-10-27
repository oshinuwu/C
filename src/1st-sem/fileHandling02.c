#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* srcFile = fopen("./fileHandling/oshin000_19.txt", "w");
    if(!srcFile) { exit(EXIT_FAILURE); }

    fwrite("Hello World!\n", sizeof(char), 13, srcFile);
    fwrite("Oshin Pant - 19\n", sizeof(char), 16, srcFile);

    fclose(srcFile);

    srcFile = fopen("./fileHandling/oshin000_19.txt", "r");
    if(!srcFile) { exit(EXIT_FAILURE); }

    FILE* destFile = fopen("./fileHandling/oshin001_19.txt", "a");
    if(!destFile) { exit(EXIT_FAILURE); }

    printf("\nWriting into another file:\n");

    char buffer[64] = {0};

    fread(buffer, sizeof(char), 64, srcFile);
    fwrite(buffer, sizeof(char), 64, destFile);
    
    fwrite("\nThank You!", sizeof(char), 11, destFile);
    fclose(destFile);
    fclose(srcFile);

    printf("\n\nName:Oshin Pant\n Roll no:19\n Lab no:2");
    getc(stdin);
    return 0;
}