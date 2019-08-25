#include <iostream>
#include <stdlib.h>

 int main()
 {
	int i;
	int len(0);

	char *num1 = (char*) malloc(100*sizeof(char));
	char *num2 = (char*) malloc(100*sizeof(char));

	std::cin >>num1;
	std::cin >>num2;

	while(num1[len++]!='\0');

	len--;

	for(i=0;i<len;i++)
	{
	  if(num1[i]!=num2[i])
	  {
	    std::cout << '1';
	  }
	  else
	  {
	    std::cout << '0';
	  }
	}
	
	std::cout << '\n';

   return 0;
 }
