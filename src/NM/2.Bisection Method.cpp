//bisection
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define F(x) (x*exp(x)-1)
#define E 0.001
int main(){
	float x1,x2,x0,f1,f2,f0,e,root;
	int itr=1;
	printf("Enter two initial guesses:\n");
	scanf("%f%f",&x1,&x2);
	f1=F(x1);
	f2=F(x2);
	if(f1*f2>0){
		printf("%f and %f do not bracket root\n",x1,x2);
	}
	else{
		while(1){
			f1=F(x1);
			f2=F(x2);
			x0=(x1+x2)/2;
			f0=F(x0);
			e=fabs(x1-x0);
			printf("Iteration %d\n",itr);
			printf("x0=%f\n",x0);
			printf("Error=%f\n",e);
			if(e<E||f0==0){
				root=x0;
				break;
			}
			else if(f0*f1<0){
				x1=x1;
				x2=x0;
			}
			else{
				x1=x0;
				x2=x2;
			}
			itr=itr+1;
		}
		printf("Root=%f\n",root);
			printf("Name:Jenisha Pandit\nRollno:61\nLab no 2");
		return 0;
	}
}



