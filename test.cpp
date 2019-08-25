#include <iostream>
#include <fstream>


 int main()
 {
   int x;

	std::cin >> x ;

	if(std::cin.eof())
	{
		std::cout << "reached end of file" << std::endl;
	}
	
	else if(std::cin.fail())
	{
		std::cout << "Input Failed!" << std::endl;
	}
	else if(std::cin.bad())
	{
		std::cout << "Stream went bad!" << std::endl;
	}
 

  return 0;
 }
