#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE* srcFile = fopen("./fileHandling/oshin_001.txt", "r");
    printf("Current Position: %ld\n", ftell(srcFile));

    fseek(srcFile, 10, SEEK_SET);
    printf("Position after moving 10 indices from start: %ld\n", ftell(srcFile));

    fseek(srcFile, 10, SEEK_CUR);
    printf("Position after moving 10 indices from current position: %ld\n", ftell(srcFile));

    fseek(srcFile, 0, SEEK_END);
    printf("Position after moving to end: %ld\n", ftell(srcFile));

    rewind(srcFile);
    printf("Position After rewinding: %ld\n", ftell(srcFile));

    fclose(srcFile);
    printf("\n\nName:Oshin Pant\n Roll no:19\n Lab no:6");
    getc(stdin);
    return 0;
}