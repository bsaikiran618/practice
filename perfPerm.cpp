#include <iostream>

 int main()
 {
 	
	int y,i;

	std::cin >> y;

	if(y%2!=0)
	 {
	   std::cout << -1;
	 }
  else
	for(i=1;i<=y;i++)
	{
	  if(i%2==0)
	  {
	    std::cout << i-1 <<' ';
	  }
	  else
	  {
	    std::cout << i+1 <<' ';
	  }
	}
  
   return 0;
 }
