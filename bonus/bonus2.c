
#include <stdio.h>

int main()
{
int a,c,temp;
int b=1001;
//scanf("%d",&b);
for (a=1; a<b; a++)
	{
	temp=a;
	c=a;
		while (c%2==0)
		{ c=c/2;}
		 while (c%2==0)
		{c=c/3;}
		while (c%5==0)
		     {c=c/5;}
if (c==1)	// remiander one
	{
	printf("%d\n", temp);
	}
}
return 0;


}
