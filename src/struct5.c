/*Create a structure type named date that has day, month and year as its members. Include this
structure as a member in another structure named employee which has name, id and salary as
other members. Use this structure to read five employee’s name, id, date of birth and salary. Pass
the structure to function using reference and display the information of employees whose salary
is greater than 15000*/
#include<stdio.h>
struct date{
    int day;
    int month;
    int year;
};
struct employee{
    char name[32];
    int age;
    int salary;
    char add[25];
    struct date d;
}emp[5];
void func(struct employee emp[5]){
    for(int i=0;i<5;i++)
    {
    if (emp[i].salary>10000){
        printf("Name:%s\n Age:%d\n Salary:%d\n Address:%s\n",emp[i].name,emp[i].age,emp[i].salary,emp[i].add);
        printf("birthdate:%d-%d-%d",emp[i].d.day,emp[i].d.month,emp[i].d.year);
    }
}}
int main(){
    for(int i=0;i<5;i++){
    printf("Enter name age salary and address of emoployee %d\n",i+1);
    scanf("%s%d%d%s",emp[i].name,&emp[i].age,&emp[i].salary,emp[i].add);
     printf("enter birthdate as (day month year):");
    scanf("%d%d%d",&emp[i].d.day,&emp[i].d.month,&emp[i].d.year);
    }
    func(emp);
    printf("Name:Oshin Pant\n Roll no:19\n Lab no:5");
getch();
return 0;
}