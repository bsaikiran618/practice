#include <iostream>


 int main()
 {
	int n,x(0),sum;
   char str[4];

	std::cin >> n;

	while(n--)
	{ 
	  std::cin >> str ;

	  sum = str[0]+str[1]+str[2];

	  if(sum == ('X'+'+'+'+'))
	  {
	    ++x;
	  }
	  else if(sum == ('X'+'-'+'-'))
	  {
	    --x;
	  }
	}

	std::cout << x << '\n';

   return 0;
 }
