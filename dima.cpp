#include <iostream>
#include <cstdlib>


 int main()
 {
  int i,n,*arr,ways(0),sum(0),x;

  std::cin >> n;
  arr= (int*) malloc(n * sizeof(int));

	for(i=0;i<n;i++)
	{
		std::cin >> x;

	   sum += x;
	}

	sum += n;


	for(i=1;i<=5;i++)
	{
	  if(((i+sum)%(n+1))!=0)
	   ways++;
	}
 
 	std::cout << ways << '\n';
 
   return 0;
 }
