#include <stdio.h> 
  
int main() 
{ 
    int rows = 5; 
    int n = 1; 
  
    // outer loop to print all rows 
    for (int i = 0; i < rows; i++) { 
  
        // innter loop to print number in each row 
        for (int j = 0; j <= i; j++) { 
            printf("%d ", n++); 
        } 
        printf("\n"); 
    } 
     printf("\n");
     printf("Name:Oshin Pant\n Roll no:19\n Lab no:6-g(ix)");
    getch();
    return 0; 
}