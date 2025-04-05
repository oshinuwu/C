#include<stdio.h>
#include<conio.h>
#include<math.h>
#define F(x) (cos(x)+2*sin(x)-x*x)
#define E 0.001
int main(){
	float x1,x2,x3,f1,f2,f3,e,root;
	int itr=0;
	printf("Enter two initial guesses:\n");
	scanf("%f%f",&x1,&x2);
	while(1){
		f1=F(x1);
 		f2=F(x2);
 		x3=x2-((x2-x1)*f2)/(f2-f1);
 			e=fabs(x3-x1);
 			printf("x%d=%f\n",itr,x1);
				if(e<E){
				root=x3;
				break;
			}
			x1=x2;
			x2=x3;
			itr++;
		}
		printf("\nRoot=%f\n",root);
		printf("\nName:Oshin Pant\nRollno:23\nLab no: 3");
		fflush(stdin);
		getchar();
		getchar();
		return 0;
	}
	
