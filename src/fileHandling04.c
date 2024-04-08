#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[32];
    char address[16];
    int age, licenseNum;
} VehicleOwner;

#define MAX_OWNERS 5

int main()
{
    VehicleOwner lists[MAX_OWNERS];

    printf("Enter Owner details:");
    for(int i = 0; i < MAX_OWNERS; i++) {
        printf("\n\tName: ");
        scanf("%s^\n", lists[i].name);
        printf("\tAddress: ");
        scanf("%s^\n", lists[i].address);
        printf("\tAge: ");
        scanf("%d", &lists[i].age);
        printf("\tLicense Num: ");
        scanf("%d^\n", &lists[i].licenseNum);
        fflush(stdin);
    }


    FILE* srcFile = fopen("./fileHandling/oshin_002.txt", "w");
    for(int i = 0; i < MAX_OWNERS; i++) {
        if(lists[i].age < 22) {
            continue;
        }

        if(!srcFile) { exit(EXIT_FAILURE); }

        fprintf(srcFile, "%s %s %d %d", lists[i].name, lists[i].address, lists[i].age, lists[i].licenseNum);
    }
    fclose(srcFile);

    srcFile = fopen("./fileHandling/oshin_002.txt", "r");
    if(!srcFile) { exit(EXIT_FAILURE); }

    printf("\n\nPRINTING SAVED DETAILS:\n");

    while (fscanf(srcFile, "%s %s %d %d",
                lists[0].name, lists[0].address, &lists[0].age, &lists[0].licenseNum) != EOF) {
        printf("\tName: %s\n\tAddress: %s\n\tAge: %d\tLicense Num: %d\n\n", 
                lists[0].name, lists[0].address, lists[0].age, lists[0].licenseNum);    
    }
    
    fclose(srcFile);


    printf("\n\nName:Oshin Pant\n Roll no:19\n Lab no:4");
    getc(stdin);
    getc(stdin);
    getc(stdin);
    return 0;
}