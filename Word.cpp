#include <iostream>
#include <stdlib.h>

int main()
{
	int upperCase (0),lowerCase(0),len(0);
	int i(0);
	char *str = (char *) malloc(100*sizeof(char));

	std::cin >> str;

   while(str[len++]!='\0');
	len--;
   
   while(str[i]!='\0')
	{
	  if(str[i]>=65 && str[i]<=90)
	   upperCase++;
	  else if(str[i]>=97 && str[i]<=122)
	   lowerCase++;
     
	  i++;
	}

	i=0;

	 if(upperCase > lowerCase)
	 {
	   while(str[i]!='\0')
		{
		  if(str[i]>=97 && str[i]<=122)
		  {
		    str[i]= 65+(str[i]-97);
		  }
		  i++;
		}
	 }
    else
	 {
	   while(str[i]!='\0')
		{
		  if(str[i]>=65 && str[i]<=90)
		  {
		    str[i]= 97+(str[i]-65);
		  }
		  i++;
		}
 	 }

	 std::cout << str;

  return 0;
}
