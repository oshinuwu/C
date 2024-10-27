/*Write a program to create a structure type named employee that has name, age, salary and
address as members. Now use array of structure to read 5 records from user. Pass the structure
to the function by value which displays the records whose salary is more than 10000*/
#include<stdio.h>
struct employee{
    char name[32];
    int age;
    int salary;
    char add[25];
}emp[5];
void func(struct employee emp[5]){
    for(int i=0;i<5;i++)
    {
    if (emp[i].salary>10000){
        printf("Name:%s\n Age:%d\n Salary:%d\n Address:%s\n",emp[i].name,emp[i].age,emp[i].salary,emp[i].add);
    }
}}
int main(){
    for(int i=0;i<5;i++){
    printf("Enter name age salary and address of emoployee %d\n",i+1);
    scanf("%s%d%d%s",emp[i].name,&emp[i].age,&emp[i].salary,emp[i].add);
    }
    func(emp);
    printf("Name:Oshin Pant\n Roll no:19\n Lab no:4");
getch();
return 0;
}