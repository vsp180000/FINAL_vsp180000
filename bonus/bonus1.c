#include <stdio.h>
#include <math.h>
#include <stdio.h>
 
int x;
double y,z;
double lnfactorial (int a);
double sterling (int x);
double difference, percent;

int main (void)
{
	int i;
	for (i=1; i <100 ; i++)
		{
		y= lnfactorial(i);
		z= sterling(i);
		difference = fabs(y-z);
		percent= (difference/y)*100;

		printf("Formula: %.4i\n",z);
		printf("error: %.4e\n", percent);
		printf("Factorial: %.4e\n",y);
		printf("n!: %d\n",i);
		}
	i=1;
		if(percent <= 0.1)
		{
		printf("the value %d\n, i");
		}
		return 0;
}

double lnfactorial (int a)
{
int m;
double n;
if (a==1)
return 0;
else
	{
	n=0;
	for (m=2; m<=a; m++)
	n = log(m) + n;
	}
return (n);
}

double sterling (int x)
{
int m;
double n;
if (x==1)
return 0;
else
        {
	n=0;
	for (m=2; m<=x; m++)
	n = log(m) + n;
	}
	return (n);
}
