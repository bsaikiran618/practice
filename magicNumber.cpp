#include <iostream>

 int main()
 {
   char num[11];
	int i,j,len(0);

	std::cin >> num;

	while(num[len++]!='\0');
	len--;

	i=0;

	while(num[i]!='\0')
	{
	  if(num[i]=='1'&& num[i+1]=='4' && num[i+2]=='4')
	  {
	    i+=3;
	  }
	  else if(num[i]=='1'&& num[i+1]=='4')
	  {
	    i+=2;
	  }
	  else if(num[i]=='1')
	  {
	    i+=1;
	  }
	  else
	  {
	    std::cout << "NO\n";
		 return 0;
	  }
	}
   std::cout << "YES\n";

	return 0;
 }
