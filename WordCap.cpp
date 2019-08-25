#include <iostream>
#include <stdlib.h>


 int main()
 {
   char *str = (char *) malloc(1001 * sizeof(char));
	int len(0);

	std::cin >> str;
	
	while(str[len++]!='\0');
	 len--;

	str =(char *)realloc(str,(len+1) * sizeof(char));

	if(str[0] >=97 && str[0] <=122)
	 str[0]=65+(str[0]-97);


	 std::cout << str;

   return 0;
 }
