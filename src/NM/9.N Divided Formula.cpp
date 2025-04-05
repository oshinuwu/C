//Write a C program to interpolate using Newton�s Divided difference method
/*Algorithm
Start
Read number of points say n
Read the value at which interpolated value is needed say, x
Read given data points
Calculate first divided difference as
for i=0 to n-1
dd[i] = fx[i]
End for
Calculate second to nth divided difference as
For i=0 to n-1
For j = n-1 to i+1
 Dd[i] = (dd[j]-dd[j-1])/(x[j]-x[j-1-i]
End for
End for
Set v=0, and p=1
Calculate interpolated value as
For i=0 to n-1
For j=0 to i-1
	P = p*(x-xj)
End for
v = v+dd[i]*p;
reset p = 1;
End for
Print the interpolated value v
Stop

C Program for Newton�s Interpolation*/
#include<stdio.h>
#include<conio.h>
int main()
{
	int n,i,j;
	float v=0,p,xv,x[10],fx[10],a[10];
	printf("Enter number of points\n");
	scanf("%d",&n);
	printf("Enter the value of x\n");
	scanf("%f",&xv);
	for(i=0;i<n;i++)
	{
		printf("Enter the value of x and fx at i = %d\n",i);
		scanf("%f%f",&x[i],&fx[i]);
		fflush(stdin);
	}
	for(i=0;i<n;i++)
	a[i] = fx[i];
	for(i=0;i<n;i++)
	{
		for(j=n-1;j>i;j--)
		{
			a[j]=(a[j]-a[j-1])/(x[j]-x[j-1-i]);
		}
	}
	v=0;
	for(i=0;i<n;i++)
	{
		p=1;
		for(j=0;j<=i-1;j++)
		p = p*(xv-x[j]);
		v = v+a[i]*p;
	}
	printf("Interpolation value = %f",v);
	printf("\nName:Oshin Pant\nRollno:23\nLab no: 9");
	getchar();
	getch();
	return 0;
}
/*Output:
Enter number of points
4
Enter the value of x
2.5
Enter the value of x and fx at i = 0
1 0
Enter the value of x and fx at i = 1
2 0.3010
Enter the value of x and fx at i = 2
3 0.4771
Enter the value of x and fx at i = 3
4 0.6021
Interpolation value = 0.400050*/


