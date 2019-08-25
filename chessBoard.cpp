#include <iostream>
#include <cstdlib>
#include <stdio.h>

 char change(char *c);

 int main()
 {
   int n,m,i,j;
	char c,man='W';

	std::cin >> n >> m;


	while(n--)
	{
		for(i=0;i<m;i++)
		{
		  std::cin >> c;

		  if(c == '-')
		  {
		   std::cout << c;
		  }
		  else if(c == '.')
		  {
		  std::cout << man;
		  }
		  change(&man);
		}
		std::cout << '\n';
		if(m%2==0)
		change(&man);
	}

 	return 0;
 }

  char change(char * c)
  {
    if(*c == 'W')
	 *c = 'B';
	 else
	 *c ='W';

	 return *c;
  }
