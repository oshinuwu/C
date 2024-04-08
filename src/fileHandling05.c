#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[32];
    int class, age, marks;
} Student;

int main()
{
    int MAX_STUDENTS = 0;
    printf("Enter the number of students:");
    scanf("%d", &MAX_STUDENTS);
    fflush(stdin);

    Student lists[MAX_STUDENTS];

    printf("Enter student details:");
    for(int i = 0; i < MAX_STUDENTS; i++) {
        printf("\n\tName: ");
        scanf("%s", lists[i].name);
        printf("\tAge: ");
        scanf("%d", &lists[i].age);
        printf("\tClass: ");
        scanf("%d", &lists[i].class);
        printf("\tMarks: ");
        scanf("%d", &lists[i].marks);
        fflush(stdin);
    }

    FILE* srcFile = fopen("./fileHandling/oshin_003.txt", "w");
    if(!srcFile) { exit(EXIT_FAILURE); }

    for(int i = 0; i < MAX_STUDENTS; i++) {
        fwrite(lists[i].name, sizeof(char), strlen(lists[i].name), srcFile);
        fprintf(srcFile, " %d %d %d\n",lists[i].age, lists[i].class, lists[i].marks);
    }
    fclose(srcFile);

    srcFile = fopen("./fileHandling/oshin_003.txt", "r");
    if(!srcFile) { exit(EXIT_FAILURE); }

    printf("\n\nPRINTING STUDENTS DETAILS WITH MARKS GREATER THAN 15:\n");

    while(fscanf(srcFile, "%s %d %d %d", lists[0].name, &lists[0].age, &lists[0].class, &lists[0].marks) != EOF){
        if(lists[0].marks > 15) {
            printf("\tName: %s\n\tAge: %d\tClass: %d\tMarks: %d\n\n", 
                lists[0].name, lists[0].age, lists[0].class, lists[0].marks);    
        }
    }
    fclose(srcFile);
    


    printf("\n\nName:Oshin Pant\n Roll no:19\n Lab no:5");
    getc(stdin);
    getc(stdin);
    return 0;
}