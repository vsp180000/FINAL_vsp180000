//#include "mytools.h"
#include <stdio.h>
#include <gsl/gsl_rng.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <math.h>


int main ()
{
double n,m,sum,x,y;
int i;  
double j=0; //inside point
double k=0; //outside point
double l=0;
double pi,Deviation,Error;
double Trial=10000;        
const gsl_rng_type *T;
gsl_rng *Rand1;
gsl_rng *Rand2;
gsl_rng_env_setup();
T = gsl_rng_default;
Rand1 = gsl_rng_alloc(T);
Rand2 = gsl_rng_alloc(T);

gsl_rng_set(Rand1, time(NULL));

for (i=0; i<Trial; i++)
	{
	gsl_rng_set(Rand2, time(NULL)*getpid());
	n=gsl_rng_uniform(Rand1);
	m=gsl_rng_uniform(Rand2);
	x=n*n;
	y=m*m;
	sum=sqrt(x+y);
	if (sum < 1)
	j +=1;	
	k++;
	l += sum;
	}

pi        = 4*(l/Trial);
Deviation = (22/7)-pi;
Error     = abs((Deviation*100*7)/22);

printf("Estimate Value of pi= %.4f\n", pi);
printf("Deviation= %.4f\n", Deviation);
printf("Error is= %.4f\n", Error);

return 0;
}
