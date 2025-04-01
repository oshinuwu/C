/*Write a C program to find integral value by using Romberg Integration

Algorithm for Romberg Integration
Start
Read lower limit and upper limit say x0 and xn
Compute h = (xn-x0)
Read value of p and q for Tpq
Compute T(0,0) using formula T(0,0) = h/2*[f(x0)+f(x1))
For i=1 to p
T[i][0] = T[i-1][0]/2+h/2i*k=12i-1  f(x0+(2k-1)/2i)
End for
For c=1 to p
For k=1 to c
m= c-k
if(k<=q)
T[m+k][k] = (4k *T[m+k][k-1]-T[m+k-1][k-1])/4k-1)
End for 
Display Romberg estimate of integration T[p][q]
stop
C program for Romberg Integration*/
#include<stdio.h>
#include<conio.h>
#include<math.h>
float f(float x)
{
	if(x==0)
	return 1.0;
	else
	return sin(x)/x;
}
int main(){
    float x0,xn,t[10][10],h,sm,sl,a;
    int i,k,c,r,m,p,q;
    printf("Enter lower and upper limit:");
    scanf("%f%f",&x0,&xn);
    printf("enter p and q required T(p,q):");
    scanf("%d%d",&p,&q);
    h=xn-x0;
    t[0][0]=h/2*((f(x0))+ (f(xn)));
    for(i=1;i<=p;i++){
        sl=pow(2,i-1);
        sm=0;
        for(k=1;k<=sl;k++){
            a=x0+(2*k-1)*h/pow(2,i);
            sm=sm+(f(a));
        }
        t[i][0]=t[i-1][0]/2+sm*h/pow(2,i);
    }
    for(c=1;c<=p;c++){
        for(k=1;k<=c && k<=q;k++){
            m=c-k;
            t[m+k][k]=(pow(4,k)*t[m+k][k-1]-t[m+k-1][k-1])/(pow(4,k)-1);
        }
    }
    printf("Romberg estimate of integration =%f",t[p][q]);
    printf("\nName:Jenisha Pandit\nRollno:61\nLab no 21");
    return 0;
}


