#include <stdio.h> 

#define MAX_BLOCKS 50 

#define MAX_FILES 10 

#define MAX_DIRECT 5 

struct inode { 

int size; 

int direct_ptr[MAX_DIRECT]; }; 

int blocks[MAX_BLOCKS]; 

int count_free_blocks() { 

int count = 0; 

for(int i = 0; i < MAX_BLOCKS; i++) { 

if(blocks[i] == 0) count++;} 

return count;} 

int allocate_blocks(struct inode *file, int size) { 

if(size > MAX_DIRECT) { 

printf("File size exceeds max direct pointers (%d).\n", MAX_DIRECT); 

size = MAX_DIRECT; } 

if(count_free_blocks() < size) { 

printf("Not enough free blocks for allocation.\n"); 

return 0;    } 

file->size = size; 

int allocated = 0; 

for(int i = 0; i < MAX_BLOCKS && allocated < size; i++) { 

if(blocks[i] == 0) { 

blocks[i] = 1; 

file->direct_ptr[allocated] = i;  // Assign block to file 

allocated++;}} 

return 1; } 

void deallocate_blocks(struct inode *file) { 

for(int i = 0; i < file->size; i++) { 

blocks[file->direct_ptr[i]] = 0;} // Mark blocks free 

file->size = 0;} // File has no blocks now 

int main() { 

struct inode files[MAX_FILES]; 

int n, choice; 

for(int i = 0; i < MAX_BLOCKS; i++) blocks[i] = 0; 

printf("Enter number of files to allocate (max %d): ", MAX_FILES); 

scanf("%d", &n); 

if(n > MAX_FILES) n = MAX_FILES; 

for(int i = 0; i < n; i++) { 

printf("\nEnter size of file %d (max %d blocks): ", i+1, MAX_DIRECT); 

int size; 

scanf("%d", &size); 

if(!allocate_blocks(&files[i], size)) { 

printf("Allocation failed for file %d\n", i+1); 

} else { 

printf("File %d allocated blocks: ", i+1); 

for(int j = 0; j < files[i].size; j++) { 

printf("%d ", files[i].direct_ptr[j]);} 

printf("\n");}} 

while(1) { 

printf("\nDo you want to delete a file? (1=Yes, 0=No): "); 

scanf("%d", &choice); 

if(choice == 0) break; 

printf("Enter file number to delete (1 to %d): ", n); 

int fnum; 

scanf("%d", &fnum); 

if(fnum < 1 || fnum > n) { 

printf("Invalid file number.\n"); 

continue;} 

deallocate_blocks(&files[fnum-1]); 

printf("File %d deleted and blocks freed.\n", fnum);} 

printf("\nFinal block allocation status (0=free,1=allocated):\n"); 

for(int i = 0; i < MAX_BLOCKS; i++) { 

printf("%d ", blocks[i]); 

if((i+1) % 10 == 0) printf("\n");} 
 fflush(stdin);
    printf("Name:\nOshin Pant\n Roll no:23\n Lab no:8-d\n Sec:A");
    getchar();
    getchar();

return 0;} 
