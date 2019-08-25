#include <iostream>
#include <stdint.h>


 int main()
 {
  uint32_t n,x,min,town_no,min_times,min_town;

  std::cin >> n;

  std::cin >> x;
  min = x;
  town_no = 1;
  min_town = town_no;
  min_times = 1;
  n--;

  while(n--)
  {
    std::cin >> x;
	 town_no++;

	 if(x < min)
	 {
	   min =x;
		min_times = 1;
		min_town = town_no;
		
	 }
	 else if(x == min)
	 {
	   min_times++;
	 }
  
  }

  if(min_times >=2)
  {
    std::cout << "Still Rozdil\n";
  }
  else
  {
    std::cout << min_town << '\n';
  }
 return 0;
 }
