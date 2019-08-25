#include <iostream>
#include <cstdlib>


 int main()
 {
   int n,m,*a,*b,i,j,count(0),max;
	int first_max = 0 ;

	std::cin >> n;

	a = (int *) malloc(n * sizeof(int));

	for(i=0;i<n;i++)
	{
	  std::cin >> a[i];
	}

	std::cin >> m;

	b = (int *) malloc(m * sizeof(int));

	for(i=0;i<m;i++)
	{
	  std::cin >> b[i];
	}

	

	for(i=0;i<n;i++)
	{
	  for(j=0;j<m;j++)
	  {
	    if((b[j]%a[i] == 0) && (first_max==0))
		  {
		    max = b[j]/a[i];
			 first_max = 1;
			 count++;
			 
		  }
		  else if(b[j]%a[i]==0)
		  {
		    if((b[j]/a[i])> max)
			 {
			   max = b[j]/a[i];
				count=1;
			 }
			 else if((b[j]/a[i])==max)
			 count++;
		  }
	  }

	}

	std::cout << count << '\n';

	free(a);
	free(b);

 return 0;
 }
