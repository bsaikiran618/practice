#include <iostream>
#include <stdlib.h>

 int main()
 {
   int count(0),len,i,j,temp;
	char *str;
	
	std::cin >> len;
	
	str = (char *)malloc((len+1) * sizeof(char));
	
	std::cin >> str;

   for(i=0;i<len-1;i++)
	{
	  temp =i;

	  for(j=temp+1;j<len;j++)
	  {
	    if(str[j]==str[temp])
		 {
		   count++;
			i++;
		 }
		 else
		 break;
	  }
     
	  
	}
  
	std::cout << count<< std::endl;

	return 0;
 }
