#include <iostream>

 int main()
 {

 	int x(0),y(0);
	int i,j,count(0);

	std::cin >>x;
	std::cin >>y;

	for(i=x+1;i<=50;i++)
	{
	 count=0;
	  for(j=1;j<=i;j++)
	  {
	    if(i%j==0)
		  count++;
	  }
		if(count==2)
		{
		  break;
		}
	}

	if(y==i)
	{
	  std::cout << "YES";
	}
	else
	{
	  std::cout << "NO";
	}
 
  return 0;
 }
