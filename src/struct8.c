/*Write a program to define Union type People with member name, age and phone number. Include
a structure Address within the union. Initialize one variable and read another variable of union
type people from user and display them to user*/
#include<stdio.h>
#include<string.h>
union people{
    char name[32];
    int age;
    unsigned phone;
    struct address{
        char city[10];
        char state[15];
        }add;
    };
int main(){
    union people ppl,ppl1;
    strcpy(ppl.name,"abc");
    ppl.age=18;
    ppl.phone=9810276655;
    strcpy(ppl.add.city,"ktm");
    strcpy(ppl.add.state,"bagmati");

    printf("Enter name,age and phone number\n");
    scanf("%s %d %u",ppl1.name,&ppl1.age,&ppl1.phone);

    printf("enter city and state\n");
    scanf("%s %s",ppl1.add.city,ppl1.add.state);

    printf("Name:%s\t Age:%d\t Phone_no:%u\t City:%s\t State:%s\t",ppl.name,ppl.age,ppl.phone,ppl.add.city,ppl.add.state);
    printf("\n");
     printf("Name:%s\t Age:%d\t Phone_no:%u\t City:%s\t State:%s\t",ppl1.name,ppl1.age,ppl1.phone,ppl1.add.city,ppl1.add.state);
    printf("\nName:Oshin Pant\n Roll no:19\n Lab no:8");
getch();
return 0;
}