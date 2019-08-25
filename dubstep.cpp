#include <iostream>


 int main()
 {
   char str[201];
	int len(0),i;
	bool printed_first( false );

	std::cin >> str;

	while(str[len++]!='\0');
	len--;

	i=0;

	while(str[i]!='\0')
	{
	  if(str[i]=='W'&&str[i+1]=='U'&&str[i+2]=='B')
	  {
	      str[i]=' ';
			str[i+1]=' ';
			str[i+2]=' ';
	  		i += 3;
	  }
	  else
	  {
		 i += 1;
	  }
	}

	for(i=0;i<len;i++)
	{
	  if(str[i]==' ')
	  {
	    if(printed_first == true)
	    std::cout << ' ';

		 i+=2;
	  }
	  else
	  {
	  	 printed_first = true;
	    std::cout << str[i];
	  }
	}


	std::cout << '\n';
 
   return 0;
 }
