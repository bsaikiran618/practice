#include <iostream>



 int main()
 {

  int currentPassengers(0),maxPassengers(0),enter(0),exit(0);
  int stops;

  std::cin >> stops;

  std::cin >> exit >> enter;

  currentPassengers-= exit;
  currentPassengers+=enter;
  maxPassengers=currentPassengers;
  stops--;

  while(stops--)
  {
     std::cin >> exit;
	  currentPassengers-=exit;
	  std::cin >> enter;
	  currentPassengers+=enter;

	  if(currentPassengers > maxPassengers)
	   maxPassengers = currentPassengers;
  }

  std::cout << maxPassengers << '\n';
 
 return 0;
 }
