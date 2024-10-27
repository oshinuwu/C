#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* srcFile = fopen("./fileHandling/oshin_001.txt", "w");
    if(!srcFile) { exit(EXIT_FAILURE); }

    fputs(
        "What is the answer to life the universe and everything?\n\
    one of the answer is 42 according to google!", srcFile);

    fclose(srcFile);

    srcFile = fopen("./fileHandling/oshin_001.txt", "r");
    if(!srcFile) { exit(EXIT_FAILURE); }

    FILE* destFile = fopen("./fileHandling/oshin_001_cpy.txt", "w");
    if(!destFile) { exit(EXIT_FAILURE); }

    printf("Writing into another file:\n");

    char word[64] = {0};
    while ( fscanf(srcFile, "%s", word) != EOF ) {
        if ( strcmp(word, "the") == 0 ||
            strcmp(word, "is") == 0 ||
            strcmp(word, "one") == 0 ) {
                continue;
            }
        fprintf(destFile, "%s ", word);
    }

    fclose(srcFile);
    fclose(destFile);
    printf("\n\nName:Oshin Pant\n Roll no:19\n Lab no:3");
    getc(stdin);
    return 0;
}