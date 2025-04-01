/*Write a C program to find integration using composite trapezoidal rule
Algorithm for composite trapezoidal rule
1. Start
2. Read value upper limit xn and lower limit x0
3. Read number of segments say k
4. Compute h = (x n -x 0 )/k
5. Computer result = f(x 0 )+f(x n )
6. For i=1 to k-1
result = result+ 2*f(x 0 +i*h)
7. Stop*/
//C program to composite trapezoidal rule
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define f(x) (3*x*x+2*x-5)
int main()
{
	float x0,xn,f0,fn,result,h,a,r;
	int i,k;
	printf("Enter lower limit\n");
	scanf("%f",&x0);
	printf("Enter upper limit\n");
	scanf("%f",&xn);
	printf("Enter value of k\n");
	scanf("%d",&k);
   	 h = (xn-x0)/k;
    	f0 = f(x0);
    	fn = f(xn);
	result = f0+fn;
	for(i=1;i<=k-1;i++)
	{
		a = x0+i*h;
		result = result+2*(f(a));
	}
	result = result*h/2;
	printf("The value of integration =%f\n",result);
		printf("\nName:Jenisha Pandit\nRollno:61\nLab no 15");
	return 0;
}

/*Output:
First Run
Enter lower limit
0
Enter upper limit
2
Enter value of k
2
The value of integration =3.000000
Second Run
Enter lower limit
0
Enter upper limit
2
Enter value of k
8
The value of integration =2.062500
*/
