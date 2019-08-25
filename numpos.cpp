#include <iostream>

 int main()
 {

 	int n,a,b,i,j,k(0);

	std::cin >> n >> a >> b;

	i = a;

	while((n-i-1)>b)
	i++;

	std::cout << n-i << '\n';

	
 
   return 0;
 }
