#include <iostream>
#include <stdint.h>


 int main()
 {
 	 uint64_t n,k,i,j(0);

	std::cin >> n >> k;
	
	if(k <= ((n+1)/2))
	{
	 std::cout << ((2*k) - 1) << '\n';
	 return 0;
	}
	k= k-((n+1)/2);

	std::cout << 2*k << '\n';

 return 0;
 }
