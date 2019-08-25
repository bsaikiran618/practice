#include <stdio.h>


 int main()
 {
   FILE *out =fopen("input","w");
	int i;

	fprintf(out ,"100000\n");

	for(i=1;i<=100000;i++)
	{
	  fprintf(out,"%d ",i);
	}
   
	fprintf(out,"\n100000\n");

	for(i=1;i<100000;i++)
	{
	  fprintf(out,"%d ",i);
	}
   
	fclose(out);

	return 0;

 }
