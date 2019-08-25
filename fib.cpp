#include <iostream>


 int main()
 {
   unsigned long int  n,i(0),j(0),k(0),a(0),b(0);

	std::cin >> n;
	
	if(n > 0)
	{ i=0;
	  j=1;

	  k=1;
	  a=0;
	  b=1;
	 }

	while(k < n)
	{
	  k=i+j;
	  
	  a=j-i;
	  b=i;

	  i=j;
	  j=k;
	  
	}
   

	std::cout << (b-a) << ' ' << a << ' ' << i << '\n';

 }
