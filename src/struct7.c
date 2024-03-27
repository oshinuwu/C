#include<stdio.h>

struct person {
    int age;
    char name[50];
};

int main() {
    struct person p[3], *p1;

    // Read data for each person
    for (int i = 0; i < 3; i++) {
        p1 = &p[i];

        printf("Enter name: ");
        scanf("%s", p1->name);
        getchar(); // Consume newline character

        printf("Enter age: ");
        scanf("%d", &p1->age);
        getchar(); // Consume newline character
    }

    // Display details of each person
    for (int i = 0; i < 3; i++) {
        printf("Details of person %d\n", i + 1);
        printf("Name: %s, Age: %d\n", p[i].name, p[i].age);
    }

    printf("\nName: Oshin Pant\nRoll No: 19\nLab No: 7\n");
    getch();
    return 0;
}
