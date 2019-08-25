#include <iostream>

 int main()
 {
   int n,i,max(0),min(0),sols[100],temp,swaps(0);

	std::cin >> n;

	for(i=0;i<n;i++)
	{ 
	  std::cin >> sols[i];
	}
	for(i=0;i<n;i++)
	{
	  if(sols[i] <= sols[min])
	  {
	    min = i;
	  }
	}
	for(i=min ;i<n-1;i++)
	{
	  temp = sols[i];
	  sols[i] = sols[i+1];
	  sols[i+1]= temp;

	  swaps++;
	}
  	for(i=0;i<n;i++)
	{
	  if(sols[i] > sols[max])
	  {
	    max = i;
	  }
	}
   for(i=max ;i>=1;i--)
	{
	  temp = sols[i];
	  sols[i] = sols[i-1];
	  sols[i-1]= temp;

	  swaps++;
	}

	
   std::cout << swaps << '\n';


   return 0;
 }
