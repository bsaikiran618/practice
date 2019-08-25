#include <iostream>


 int main()
 {
   int arr[7];
	int n ,i,pagesLeft;
	bool finished = false;

	std::cin >> n;

	pagesLeft = n;

	for(i=0;i<7;i++)
	std::cin >> arr[i];

	while(!finished)
	{
	  for(i=0;i<7;i++)
	  {
	    pagesLeft -= arr[i];
		
			if(pagesLeft<=0)
			{
			  finished=true;
			  break;
			}
	  }
	}

	std::cout << i+1 << '\n';
 
  return 0;
 }
