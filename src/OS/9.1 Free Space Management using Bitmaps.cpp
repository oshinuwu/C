#include <stdio.h> 

int main() { 

    int total_blocks, i, n, block; 

    int free_blocks_count = 0; 

    printf("Enter total number of blocks: "); 

    scanf("%d", &total_blocks); 

    int bitmap[total_blocks]; 

    for(i = 0; i < total_blocks; i++) { 

        bitmap[i] = 0;} 

    printf("Enter number of blocks to allocate: "); 

    scanf("%d", &n); 

 printf("Enter block numbers to allocate (0 to %d):\n", total_blocks - 1); 
 fflush(stdin);

  for(i = 0; i < n; i++) { 

        scanf("%d", &block); 

        if(block >= 0 && block < total_blocks) { 

            if(bitmap[block] == 0) { 

                bitmap[block] = 1; // Mark block as allocated 

            } else { 

                printf("Block %d is already allocated.\n", block);} 

        } else { 

            printf("Invalid block number %d.\n", block);}} 

    printf("\nBitmap status (0=free, 1=allocated):\n"); 

    for(i = 0; i < total_blocks; i++) { 

        printf("%d ", bitmap[i]); 

        if((i + 1) % 10 == 0) 

            printf("\n");} 

    for(i = 0; i < total_blocks; i++) { 

        if(bitmap[i] == 0) 

            free_blocks_count++;} 

     printf("\nTotal free blocks: %d\n", free_blocks_count); 

 fflush(stdin);
    printf("Name:Oshin Pant\n Roll no:23\n Lab no:9-a\n Sec:A");
    getchar();
    getchar();

    return 0;} 
