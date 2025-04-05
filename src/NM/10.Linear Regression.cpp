/*AlgorithmStart
Read number of points, say n
Read given data points say x[i] and y[i]
Find summations of x, y, xy and x2 as below
For i=0 to n-1
sx = sx+x[i]
sy = sy+y[i]
sxy =  sxy+x[i]*y[i]
sx2 = sx2+x[i]*x[i]
End for
Calculate value of a and b as
B = ((n*sxy)-(sx*sy)/((n*sx2)-(sx*sx)) and b = (sy/n)-(b*sx/n)
Print equation  y =  a+bx
Stop 

C program for linear regression*/
#include<stdio.h>
#include<conio.h>
int main()
{
	int i,j,k,n;
	float a=0,b=0, x[10],y[10],sx=0,sy=0,sxy=0,sx2=0;
	printf("Enter number of points\n");
	scanf("%d",&n);
	printf("Enter value of x and fx\n");
	for(i=0;i<n;i++)
	{
		scanf("%f%f",&x[i],&y[i]);
	}
	for(i=0;i<n;i++)
	{
		sx  = sx+x[i];
		sy = sy+y[i];
		sxy = sxy+x[i]*y[i];
		sx2 = sx2+x[i]*x[i];		 
	}
	b = ((n*sxy)-(sx*sy))/((n*sx2)-(sx*sx));
	a = (sy/n)-(b*sx/n);
	printf("Fitted line is %f+%fx",a,b);
	printf("\nName:Oshin Pant\n Rollno:23\n Lab no: 10");
	getchar();
	getch();
}
/*Output:
Enter number of points
5
Enter value of x and fx
1 3
2 5
3 7
4 10
5 12
Fitted line is 0.500000+2.300000x
*/
