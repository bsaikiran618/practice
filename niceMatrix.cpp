#include <iostream>


 int main()
 {
	int row(0),col(0);
	int x,read(0);
   int moves(0);
	
	while(true)
	{
	  std::cin >> x;

	  read++;
    
	   row = (read-1)/5;
      col = (read -1)%5;

		if(x==1)
		break;

	}

  
   moves+= (((row-2)>0)?row-2:2-row) + (((col -2)>0)?col-2:2-col);

	std::cout << moves;
	
 return 0;
 }
