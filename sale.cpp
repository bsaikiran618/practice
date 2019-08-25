#include <iostream>
#include <cstdlib>

 int main()
 {
 	int m,n,*tv,i,j,temp;

	std::cin >> n >> m;


	tv = (int *) malloc(sizeof(int) * n);

	for(i=0;i<n;i++)
	{
	  std::cin >> tv[i];
	}

	for(i=1;i<n;i++)
	{
		temp =tv[i];
		j=i-1;
			
			while(j>=0 && temp<tv[j])
			{
			  tv[j+1]=tv[j];
			  j--;
			}

		tv[j+1]=temp;
	}

	n=0;

	for(i=0;i<m;i++)
	{
	 if(tv[i]<=0)
	 n+=tv[i];  // reusing variable 'n' for a different purpose 
	}

	std::cout << (-1)*n << '\n';
 
  return 0;
 }
