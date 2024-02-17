#include <stdio.h> 
  
int main() 
{ 
    int rows = 5; 
  
    // first loop for printing rows 
    for (int i = 0; i < rows; i++) { 
  
        // second loop for printing character in each rows 
        for (int j = 0; j <= i; j++) { 
            printf("#"); 
        } 
        printf("\n"); 
    } 
     printf("\n");
     printf("Name:Oshin Pant\n Roll no:19\n Lab no:6-g(viii)");
    getch();
    return 0; 
}