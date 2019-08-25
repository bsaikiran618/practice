#include <iostream>
#include <stdlib.h>
 int main()
 {
	unsigned short n,len;
	char *str = (char*)malloc(101*sizeof(char));

	std::cin >> n;

	while(n--)
	{
	  len=0;
	  std::cin >> str;
	  
	  while(str[len++]!='\0');
	  len--;
	  
	  if(len > 10)
	  {
	   std::cout << str[0] << len-2 << str[len-1] << '\n';
	  }
	  else
	  {
	   std::cout << str << '\n';
	  }
	}


  return 0;
 }
