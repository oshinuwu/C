/*Algorithm
1. Start
2. Read the number of points say n
3. Read the value at which value is needed, say x
4. Read the given data points
5. Calculate the values Li as below
For i= 1 to n
For j=1 to n
If(j!=i)
L[i] = L[i]*((x-x[j])/(x[i]-x[j]))
end if
end for
6. Calculate interpolated value at x as below
For i=1 to n
v = v +fx[i]*L[i];
End for
7. Print the interpolation value v at x
8. Stop*/

//C program for Lagrange Interpolation
#include<stdio.h>
#include<conio.h>
int main()
{
	 float x[100], y[100], xp, yp, p;
	 int i,j,n;	 
	 printf("Enter number of data: ");
	 scanf("%d", &n);
	 printf("Enter data:\n");
	 for(i=1;i<=n;i++)
	 {
		  printf("x[%d] = ", i);
		  scanf("%f", &x[i]);
		  printf("y[%d] = ", i);
		  scanf("%f", &y[i]);
	 }
	 printf("Enter interpolation point: ");
	 scanf("%f", &xp);	 
	 for(i=1;i<=n;i++)
	 {
		  p=1;
		  for(j=1;j<=n;j++)
		  {
			   if(i!=j)
			   {
			    	p = p* (xp - x[j])/(x[i] - x[j]);
			   }
		  }
		  yp = yp + p * y[i];
	 }
	 printf("Interpolated value at %.3f is %.3f", xp, yp);
	 printf("\nName:Oshin Pant\n Rollno:23\n Lab no: 8");
	 getchar();
	 getch();
}

