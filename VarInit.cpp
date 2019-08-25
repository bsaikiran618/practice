#include <iostream>


 int main()
 {
   int x = 5; // copy initialization/assignment
	int y(6);  // direct initialization
	int z{7};  // uniform initialization (or) brace initialization
				  // brace initialization is only available in c++11

	std::cout << "x value:"<< x << '\n';
	std::cout << "y value:"<< y << '\n';
	std::cout << "z value:"<< z << '\n';

	return 0;
 
 
 }
