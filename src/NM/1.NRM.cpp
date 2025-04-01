//Newton Rapson Method
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define F(x) (x*x*x+x*x-1)
#define D(x) (3*x*x+2*x)
#define E 0.001
int main(){
	float x1,x2,f1,f2,e,root;
	int itr;
	printf("Enter initial guess:\n");
	scanf("%f",&x1);

		while(1){
			f1=F(x1);
			f2=D(x1);
			if(f2==0){
				printf("Divide by zero error");
				break;
			}
			x2=x1-f1/f2;
			e=fabs(x2-x1);
			printf("Iteration %d\n",itr);
			printf("x%d=%f\n",itr,x1);
			printf("Error=%f\n",e);
			if(e<E){
				root=x2;
				break;
			}
			x1=x2;
			itr= itr+1;
		}
		printf("Root=%f\n",root);
		printf("Name:Jenisha Pandit\nRollno:61\nLab no 1");
		return 0;
	}
		
