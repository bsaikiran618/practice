#include <iostream>
#include <stdlib.h>

 int main()
 {
	char *name1 = (char*) malloc(101*sizeof(char));
	char *name2 = (char*) malloc(101*sizeof(char));
	char *jumbl = (char*) malloc(202*sizeof(char));
	int i,j,len1(0),len2(0),len3(0);

	std::cin >> name1 >> name2 >> jumbl ;

	while(name1[len1++]!='\0');
	len1--;
	while(name2[len2++]!='\0');
	len2--;
	while(jumbl[len3++]!='\0');
	len3--;

	if((len1+len2) != len3)
	{
	  std::cout << "NO" << '\n';
	  return 0;
	}

	for(i=0;i<len1;i++)
	{
	  for(j=0;j<len3;j++)
	  {
	   if(jumbl[j] == name1[i])
		 {
		   jumbl[j] ='^';
			break;
		 }
	  }
	}
	for(i=0;i<len2;i++)
	{
	  for(j=0;j<len3;j++)
	  {
	   if(jumbl[j] == name2[i])
		 {
		   jumbl[j] ='^';
			break;
		 }
	  }
	}

   for(i=0;i<len3;i++)
	{
	  if(jumbl[i]!='^')
	  {
	    std::cout << "NO" << '\n';
		 return 0;
	  }
	}

	std::cout << "YES" <<'\n';

   return 0;
 }
