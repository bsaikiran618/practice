#include <iostream>
#include <cmath>

  int main()
  {

  		int i,j,count(0),m,n,sqrt1,sqrt2;

		std::cin >> n >> m;

		sqrt1 = sqrt(n) + 1;
		sqrt2 = sqrt(m) + 1;

		for(i=0;i<sqrt1;i++)
		{
		  for(j=0;j<sqrt2;j++)
		  {
		    if((((i*i) + (j))==n) && ((i+(j*j))==m))
			 count++;
		  }
		}

		std::cout << count << '\n';
  
    return 0;
  }
