//Write a C program to find integration using trapezoidal rule
/*Algorithm for trapezoidal rule
1. Start
2. Read value of lower and upper limit say x0 and x1
3. Calculate f(x0) and f(x1)
4. Calculate h = (x1-x0)
5. Calculate the value of integration by using formula
v = (f(x 0 )+fx(x 1 )
6. Display the value of integration “v”
7. Stop*/
//C program for trapezoidal rule
#include<stdio.h>
#include<conio.h>
#define F(x) (x*x*x+3)
int main()
{
	float h, x0,x1,x2,x,v,f0,f1;
	printf("Enter upper limit and lower limit\n");
	scanf("%f%f",&x1,&x0);
	h = x1-x0;
	f1 = F(x1);
	f0 = F(x0);
	v = h*(f0+f1)/2;
	printf("The value of integration = %f",v);
		printf("\nName:Jenisha Pandit\nRollno:61\nLab no 14");
	getch();
	return 0;
}

/*Output:
Enter upper limit and lower limit
8 2
The value of integration = 1578.000000*/
