#include <iostream>


 int main()
 {
   int amzg(0),max,min,n,x;

	std::cin >> n;

	std::cin >> min;
	max = min;

	n--;

	while(n--)
	{
	  std::cin >> x;

	  if((x < min))
	  {
	    min =x;
		 amzg++;
	  }
	  else if(x > max)
	  {
	    max = x;
		 amzg++;
	  }
	}
  
   std::cout << amzg << '\n';
 
   return 0;
 }
