/*
1.	Start
2.	Read number of data points say n
3.	Read given data points say x[i], y[i]
4.	Calculate needed summation as below
sx = sx+x[i];
slogy = slogy+logy[i];
sxy = sxy+x[i]*logy[i];
sx2 = sx2+x[i]*x[i];
End for
5.	Calculate values of b and a by using following formulae
a = ((n*sxy)-(sx*slogy))/((n*sx2)-(sx*sx))
r = (slogy)/n)-(b*sx/n)
a = er
6.	Display the equation y = aebx
7.	Stop
*/
//Write a C program for exponential regression
#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	int n,i,j,k;
	float a=0,b=0,r, x[10],y[10],sx, slogy=0, sxy=0, sx2=0;
	printf("Enter number of points\n");
	scanf("%d",&n);
	printf("Enter the value of x and fx\n");
	for(i=0;i<n;i++)
	{
		scanf("%f%f",&x[i],&y[i]);
	}
	for(i=0;i<n;i++)
	{
		sx = sx+x[i];
		slogy = slogy+log(y[i]);
		sxy = sxy+x[i]*log(y[i]);
		sx2 = sx2+x[i]*x[i];
	}
	b = ((n*sxy)-(sx*slogy))/((n*sx2)-(sx*sx));
	r = (slogy/n)-(b*sx/n);
	a =  exp(r);
	printf("Fitted Curve is y = %fe^%fx",a,b);
	printf("\nName:Oshin Pant\n Rollno:23\n Lab no: 11");
	getchar();
	getch();
}

