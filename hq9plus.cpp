#include <iostream>
#include <cstdlib>

 int isValid(char c);

 int main()
 {
	char *str,c;
	int len(0);

	str = (char*) malloc(101 * sizeof(char));

	std::cin >> str;

	while(str[len++]!='\0');
	len--;

	while(len>=0)
	{
		c = str[len];

	  if((c=='H' || c=='Q' || c=='9')&&(c>=33 && c<=126))
	  {
	    std::cout << "YES" << '\n';
		 return 0;
	  }
	  len--;
	}

	std::cout << "NO" << '\n';

   return 0;
 }

