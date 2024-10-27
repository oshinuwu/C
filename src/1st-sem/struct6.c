/*Define a structure type Employee to store the following data about an employee: age (integer),
name (string) and salary(integer). Create a program with following functions:
a. A function to read the employees’ data into the array.
b. A function to display records of each employee.
c. A function to sort the records of employee on the basis of salary in descending order.
Suppose an organization has 10 employees. Now read those details and display them. Sort the
detail in descending order on the basis of salary and display the sorted list.*/
#include<stdio.h>
struct employee{
    char name[32];
    int age;
    int salary;
}emp[10];
void read(struct employee emp[10]){
 for(int i=0;i<10;i++){
    printf("Enter name ,age and salary of emoployee %d\n",i+1);
    scanf("%s%d%d",emp[i].name,&emp[i].age,&emp[i].salary);
 }
}
void display(struct employee emp[10]){
    
     for(int i=0;i<10;i++)
    {
    
        printf("Name:%s\t Age:%d\t Salary:%d\t ",emp[i].name,emp[i].age,emp[i].salary);
        printf("\n");
}}
void sort(struct employee emp[]) {
    struct employee temp;
    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (emp[i].salary < emp[j].salary) {
                temp = emp[i];
                emp[i] = emp[j];
                emp[j] = temp;
            }
        }
    }
}
int main(){
    read(emp);
    display(emp);
    sort(emp);
    printf("the details after sorting:\n");
    display(emp);
    printf("Name:Oshin Pant\n Roll no:19\n Lab no:6");
getch();
return 0;
}