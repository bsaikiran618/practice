#include <iostream>
#include <stdio.h>

 int main()
 {

   char c;

	while((c = getchar())!='\n')
	{
	  switch(c)
	  {
	    case 'a':
		 case 'A':
		 case 'e':
		 case 'E':
		 case 'i':
		 case 'I':
		 case 'o':
		 case 'O':
		 case 'u':
		 case 'U':
		 case 'Y':
		 case 'y': continue;
	  }
		
	   std::cout << '.' <<(char)((c>=65 && c <=90)?(97 + c - 65):c);
	}

	std::cout << '\n';
 
   return 0;
 }
