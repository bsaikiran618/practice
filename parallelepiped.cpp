#include <iostream>
#include <cmath>

 int main()
 {
   unsigned int a,b,c;

	std::cin >> a >> b >> c; 

	std::cout << 4*(sqrt((c*b)/a) + sqrt((a*c)/b) + sqrt((a*b)/c)) << '\n';
	
	return 0;
 }
