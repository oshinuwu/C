/*Write a function that compares two given dates. To store a date use a structure type that contains
three members namely day, month and year. If the dates are equal the function should return 0,
otherwise it should return 1. Display the results from main() function.
*/
#include<stdio.h>
struct date{
    int day;
    int month;
    int year;
}d1,d2;
int compare_date(struct date d1,struct date d2){
    if(d1.day==d2.day && d1.month==d2.month && d1.year==d2.year){
        return 0;
    }
    else {
        return 1;
}}
int main(){
    printf("enter date as (day month year):");
    scanf("%d%d%d",&d1.day,&d1.month,&d1.year);
    printf("enter date as (day month year):");
    scanf("%d%d%d",&d2.day,&d2.month,&d2.year);
    if (compare_date(d1,d2)==0){
        printf("returned 0\n");
    }
    else{
        printf("returned 1\n");
    }
    printf("Name:Oshin Pant\n Roll no:19\n Lab no:3");
getch();
return 0;
}