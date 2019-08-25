#include <stdio.h>
#include <iostream>
 int main()
 {
  
   char word[] = "hello";
	int i=0;
	char c;

	while((c = getchar())!='\n')
	{
	  if(c == word[i])
	   i++;
	}

	if(i==5)
	std::cout << "YES\n";
	else
	std::cout << "NO\n";

   return 0;
 }
