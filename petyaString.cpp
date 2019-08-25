#include <iostream>
#include <cstdlib>

 int main()
 {
	char *str1 = (char*) malloc(101 * sizeof(char));
	char *str2 = (char*) malloc(101 * sizeof(char));
	int len(0),i(0);
	char c1,c2;

	std::cin >> str1 >> str2 ;

	while(str1[len++]!='\0');

	len--; //true length

	while(i<len)
	{
		c1 = str1[i];
		c2 = str2[i];

		if(c1>=65 && c1 <=90)
		{
		  c1 = 97 + (c1 - 65);
		}
		if(c2>=65 && c2 <=90)
		{
		  c2 = 97 + (c2 - 65);
		}
		
		if(c1 < c2)
		{
		  std::cout << -1 << '\n';
		  return 0;
		}
		if(c1 > c2)
		{
		  std::cout << 1 << '\n';
		  return 0;
		}

	  i++;
	}

	std::cout << 0 << '\n';
	
	return 0;
 }
