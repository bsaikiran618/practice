#include <stdio.h>

int main()
 {
   double sum(0),x;
	int n,i;

	scanf("%d",&n);

	i=n;

	while(n--)
	{
	  scanf("%lf",&x);
	  sum+=x;
	}

	printf("%.12lf\n",(sum/(double)i));
 
 }
