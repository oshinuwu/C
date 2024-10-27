//structure type named student that has name, roll, marks, and remarks (initialize one and take input for another)
#include<stdio.h>
#include<string.h>
struct student{
    char name[32];
    int roll;
    int marks;
    char remarks;
};
int main(){
    struct student s1,s2;
    strcpy(s2.name,"abc");
    s2.roll=1;
    s2.marks=53;
    s2.remarks='A';
    printf("Enter name roll no marks and remarks for a student");
    scanf("%s%d%d %c",s1.name,&s1.roll,&s1.marks,&s1.remarks);
    printf("Name:%s\n Roll no:%d\n Marks:%d\n Remarks:%c\n",s1.name,s1.roll,s1.marks,s1.remarks);
     printf("Name:%s\n Roll no:%d\n Marks:%d\n Remarks:%c\n",s2.name,s2.roll,s2.marks,s2.remarks);
    printf("Name:Oshin Pant\n Roll no:19\n Lab no:1");
    getch();
    return 0;
}