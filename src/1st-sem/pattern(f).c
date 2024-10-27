#include <stdio.h> 
  
int main() 
{ 
    int rows = 5; 
  
    // first loop to print all rows 
    for (int i = 0; i < rows; i++) { 
  
        // first inner loop to print the * in each row 
        for (int j = 0; j < rows - i; j++) { 
            printf("* "); 
        } 
        printf("\n"); 
    } 
     printf("\n");
     printf("Name:Oshin Pant\n Roll no:19\n Lab no:6-g(vi)");
    getch();
    return 0;
}