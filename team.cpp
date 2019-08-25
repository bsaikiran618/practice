#include <iostream>


 int main()
 {
   int n,i1,i2,i3,solved(0);
	
	std::cin >> n;

	while(n--)
	{
	  std::cin >> i1;
     std::cin >> i2;
     std::cin >> i3;

	  if((i1+i2+i3)>=2)
	   solved++;
	}

	std::cout << solved << '\n';
 }
