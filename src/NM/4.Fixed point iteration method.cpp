#include<stdio.h>
#include<conio.h>
#include<math.h>
#define F(x) (x*x*x+x*x-1)
#define D(x) (1/sqrt(x+1))
#define E 0.001
int main(){
	float x1,x2,f1,f2,e,root;
	int itr=1;
	printf("Enter the initial guesses:\n");
	scanf("%f",&x1);
	while(1)
	{
		x2=D(x1);
		e=fabs(x2-x1);
		printf("x%d=%f\n",itr,x1);
			printf("x%d=%f\n",itr, x1);
			
				if(e<E){
				root=x2;
				break;
			}
			x1=x2;
			itr=itr+1;
		}
		printf("Root=%f\n",root);
		printf("\nName:Oshin Pant\nRollno:23\nLab no: 4");
		fflush(stdin);
		getchar();
		getchar();
		return 0;
	}



