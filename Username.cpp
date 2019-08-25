#include <iostream>
#include <stdlib.h>

 int main()
 {
  
	short i,j,len(0),distinct(1);
	char *uname = (char *)malloc(100*sizeof(char));
	char temp;

	std::cin >> uname;

	while(uname[len++]!='\0');
	len--;

	for(i=1;i<len;i++)
	{
	  j=i-1;
	  temp=uname[i];

	  while(uname[j]>temp && j>=0)
	  {
		 uname[j+1] = uname[j];
		 j--;
	  }
	  uname[j+1] = temp;
	}


	for(i=1;i<len;i++)
	{
	  if(uname[i]==uname[i-1])
	  {
	    continue;
	  }
	  else
	  {
	    distinct++;
	  }
	}

   std::cout << ((distinct%2==0)?"CHAT WITH HER!":"IGNORE HIM!") << '\n' ;
 
   return 0;
 }
